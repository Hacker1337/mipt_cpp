#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::min;

#include <vector>

using std::vector;

#include "point_and_rectangle.cpp"

int main()
{

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // изменить стандартный поток ввода вывода

    std::string expression;
    std::getline(std::cin, expression);

    Point p(1, 2);
    cout << expression << endl;
    // code goes here return QO;
}