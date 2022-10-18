// #include <iostream>

// using std::boolalpha;
// using std::cerr;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::min;

// #include <vector>
// using std::vector;

// int main()
// {

//     freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout); // изменить стандартный поток ввода вывода
// }

#include <iostream>
#include <cmath>
using std::boolalpha;
using std::cout;
using std::endl;
using std::initializer_list;
using std::ostream;
using std::signbit;
template <typename T1, typename T2>
struct pair
{
    T1 first;
    T2 second;
    pair() = default;
    pair(T1 a, T2 b) : first(a), second(b) {}
    pair(const pair &a) : pair(a.first, a.second) {}
};
template <typename T1, typename T2>
auto make_pair(T1 a, T2 b) { return pair<T1, T2>(a, b); }
template <typename T1, typename T2>
auto minmax(T1 a, T2 b) { return a < b ? make_pair(a, b) : make_pair(b, a); }
template <typename T>
auto min(T a, T b) { return a < b ? a : b; }
template <typename T>
auto max(T a, T b) { return a > b ? a : b; }
template <typename T>
class point : public pair<T, T>
{ //
public:
    point() = default;
    point(T x, T y) : pair<T, T>(x, y) {}
    point(const pair<T, T> &a) : pair<T, T>(a) {}
    point operator-(const point &b) const { return point(pair<T, T>::first - b.first, this->second - b.second); }
    T operator*(const point &b) const { return this->first * b.second - this->second * b.first; }
    point operator*(T b) const { return point(b * this->first, b * this->second); }
    T operator[](int i) const { return i ? this->second : this->first; }
    T &operator[](int i) { return i ? this->second : this->first; }
    friend ostream &operator<<(ostream &out, const point &a) { return out << '(' << a.first << ',' << a.second << ')'; }
};

template <typename U>
class Segment
{

public:
    Segment() = default;
    point<U> v[2];
    Segment(point<U> p0, point<U> p1)
    {
        v[0] = p0;
        v[1] = p1;
    }
};
template <typename U>
class Triang
{
    point<U> v[3];

public:
    Triang() = default;
    Triang(const initializer_list<point<U>> &a)
    {
        auto i = 0u;
        for (const auto &x : a)
            v[i++] = x;
    }
    Triang(point<U> p0, point<U> p1, point<U> p2)
    {
        v[0] = p0;
        v[1] = p1;
        v[2] = p2;
    }
    friend ostream &operator<<(ostream &out, const Triang &a)
    {
        out << '[';
        for (const auto &x : a.v)
            out << x;
        return out << ']';
    }
    bool cros(const Triang &);

private:
    bool cros_my(const Triang &) const;
};

template <typename T>
int sgn(T val) // math signum function
{
    return (T(0) < val) - (val < T(0));
}

template <typename U>
int point_segm_orientation(const point<U> p, const Segment<U> s)
{
    U x1 = p.first - s.v[0].first;
    U x2 = s.v[1].first - s.v[0].first;

    U y1 = p.second - s.v[0].second;
    U y2 = s.v[1].second - s.v[0].second;

    return sgn(x1 * y2 - x2 * y1);
}

template <typename U>
bool point_in_segm(const point<U> p, const Segment<U> s) // checks if point is in segment
{
    U x1 = p.first - s.v[0].first;
    U x2 = s.v[1].first - s.v[0].first;

    U y1 = p.second - s.v[0].second;
    U y2 = s.v[1].second - s.v[0].second;
    U scal_mult = x1 * x2 + y1 * y2;
    return (x1 * y2 - x2 * y1 == 0) && (scal_mult >= 0) && (scal_mult <= (x2 * x2 + y2 * y2));
}

template <typename U>
bool intersept(Segment<U> a, Segment<U> b)
{
    return point_segm_orientation(a.v[0], b) != point_segm_orientation(a.v[1], b) &&
           point_segm_orientation(b.v[0], a) != point_segm_orientation(b.v[1], a);
}

template <typename U>
bool Triang<U>::cros(const Triang &b)
{
    return this->cros_my(b) || b.cros_my(*this);
}
template <typename U>
bool Triang<U>::cros_my(const Triang &b) const
{
    Segment<U> A_segms[3];
    for (int i = 0; i < 3; i++)
    {
        A_segms[i] = Segment<U>(this->v[i], this->v[(i + 1) % 3]);
    }

    // check if point of b are on borders of *this
    for (auto segm : A_segms)
    {
        for (auto p : b.v)
        {
            if (point_in_segm(p, segm))
            {
                return true;
            }
        }
    }

    // check if one of the point if in the other triangle

    for (auto p : b.v)
    {
        auto t0 = point_segm_orientation(p, A_segms[0]);
        auto t1 = point_segm_orientation(p, A_segms[1]);
        auto t2 = point_segm_orientation(p, A_segms[2]);
        if (point_segm_orientation(p, A_segms[0]) == point_segm_orientation(p, A_segms[1]) &&
            point_segm_orientation(p, A_segms[1]) == point_segm_orientation(p, A_segms[2]))
        {
            return true;
        }
    }

    // check if two segments intersept
    for (int i = 0; i < 3; i++)
    {
        Segment<U> B_segm(b.v[i], b.v[(i + 1) % 3]);

        for (auto segm : A_segms)
        {
            if (intersept(B_segm, segm))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    // Segment<int> s0(point<int>(0, 0), point<int>(2, 0));
    // point<int> p0(0, 3);
    // cout << point_segm_orientation(p0, s0) << endl;

    // Segment<int> s1(point<int>(2, 0), point<int>(0, 2));
    // point<int> p1(0, 3);
    // cout << point_segm_orientation(p1, s1) << endl;

    // Segment<int> s2(point<int>(0, 2), point<int>(0, 0));
    // point<int> p2(0, 3);
    // cout << point_segm_orientation(p2, s2) << endl;

    // Segment<int> s2(point<int>(0, 0), point<int>(1, 1));
    // point<int> p2(2, 2);
    // cout << boolalpha << point_in_segm(p2, s2) << endl;

    // Segment<int> s2(point<int>(0, 0), point<int>(2, 2));
    // point<int> p2(1, 1);
    // cout << boolalpha << point_in_segm(p2, s2) << endl;

    // return 0;

    Triang<double> a{{0., 0.}, {2., 0.}, {0., 2.}}, b{{0., 3.}, {3., 0.}, {3., 3.}};
    cout << a << endl;
    cout << b << endl;
    cout << boolalpha << a.cros(b) << endl;
    Triang<double> c{{1., 1.}, {1., -1.}, {-1., 1.}};
    cout << a << endl;
    cout << c << endl;
    cout << boolalpha << a.cros(c) << endl;
    Triang<double> d{{0., 0.}, {0., -2.}, {-2., 0.}};
    cout << a << endl;
    cout << d << endl;
    cout << boolalpha << a.cros(d) << endl;
    Triang<double> e{{3., 3.}, {0., -2.}, {-2., 0.}};
    cout << a << endl;
    cout << e << endl;
    cout << boolalpha << a.cros(e) << endl;
    Triang<double> f{{1.75, 1.75}, {1.75, 1.}, {1., 1.75}};
    cout << a << endl;
    cout << f << endl;
    cout << boolalpha << a.cros(f) << endl;

    
    cout << e << endl;
    cout << f << endl;
    cout << boolalpha << e.cros(f) << endl;


}