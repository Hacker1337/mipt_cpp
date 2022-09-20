#include <iostream>
using namespace std;

class Vector {
    unsigned n = 0;
    int *p = nullptr;
public:
    Vector() = default;
    Vector(const Vector& x) : Vector(x.n) {
        for(auto i=0; i<x.n; ++i) 
            p[i] = x.p[i];
    }
    Vector(int n) : n(n), p(new int[n]) {}
    Vector(const initializer_list<int>& a) : Vector(a.size()) {// Инициализирующий конструктор
        auto i = 0u;
        for(const auto& x : a) p[i++] = x;
    }
    ~Vector() { delete [] p; }
    Vector& operator=(Vector& a) {
        delete[] p;
        Vector b = Vector(a.n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }
        swap(b, *this);
        return *this;
    }
    Vector& operator=(Vector&& a) {  
        delete[] p;
        this->n = a.n;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = a[i];
        }
        a.n = 0;
        a.p = nullptr;
        return *this;
    }

    int& operator[ ] (unsigned i) {
        return p[i];
    };
    Vector& operator++() {
        for(int i = 0; i < n; i++) {
            p[i] += 1;
        }
        return *this;
    };
    Vector operator++(int) { // postfix ++
        Vector result(*this);
        ++(*this);
        return result;
    };
    Vector operator+(const Vector& add) {
        Vector res(add.n);
        for (int i = 0; i < add.n; i++) {
            res[i] = this->p[i] + add.p[i];
        }
        return res;
    };
    Vector operator*(int k) const {
        Vector res(*this);
        for(int i = 0; i < n; i++) {
            res[i] *= k;
        }
        return res;
    };
    unsigned size() { return this->n; }
    int* begin() { return p; }
    int* end() { return p+n; }

    friend ostream& operator<<(ostream&, const Vector&);
    // Объявление дружественной функции
};

ostream& operator<<(ostream& out, const Vector& a) {
    // и её определение вне класса
    out << '(';
    for(auto i=0u; i<a.n; ++i) 
        out << a.p[i] << (i==a.n-1 ? "" : " ");
    return out << ')';
}

int main() {
    Vector a {1,2,3};
    Vector b {3, 2, 1};
    cout << a << endl;
    cout << a[1] << endl;
    cout << a++ << endl;
    cout << a[1] << endl;

    cout << a[1] << endl;

    cout << a+b << endl;

    cout << "a is " << a << endl;
    cout << "a*5 is " << a*5 << endl;

}