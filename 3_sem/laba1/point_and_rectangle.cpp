#include <iostream>

struct Point
{

    unsigned long long const x, y;
    Point(unsigned long long x, unsigned long long y) : x(x), y(y) {}
    Point minx(Point const &rha) const
    {
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(Point const &rha) const
    {
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx(Point const &rha) const
    {
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy(Point const &rha) const
    {
        return Point(x, rha.y > y ? rha.y : y);
    }
    void print() const
    {
        std::cout << '(' << x << ',' << y << ')';
    }
};

class Rectangle : Point
{
    // Point corner;

public:
    Rectangle() : Point(0, 0) {}

    Rectangle(Point const &rha) : Point(rha) {}
    Rectangle(unsigned long long x, unsigned long long y) : Point(x, y) {}

    Rectangle operator+(Rectangle const &rha) const
    {
        return Rectangle(this->maxx(rha).maxy(rha));
    };
    Rectangle operator*(Rectangle const &rha) const {
        return Rectangle(this->minx(rha).miny(rha));
    }
    // todo

    using Point::print;

    // void print() const
    // {
    //     corner.print();
    // };
};