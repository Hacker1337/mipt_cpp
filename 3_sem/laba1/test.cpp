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
    int i = 0;

    Point p(1, 2);
    // p.print();

    Rectangle a; // without params;
    cout << "Finished test " << ++i << endl;
    a.print(); 
    cout << endl;
    cout << "Finished test " << ++i << endl;
    
    Rectangle b(p);
    b.print();
    cout << endl;
    cout << "Finished test " << ++i << endl;


    Rectangle e(5, 4);
    e.print(); cout << endl;
    cout << "Finished test " << ++i << endl;

    Rectangle c = b + a;
    a.print(); cout << " + "; b.print(); cout << " = ";c.print();
    cout << endl;
    cout << "Finished test " << ++i << endl;


    Rectangle d = c*e;
    c.print(); cout << " * "; e.print(); cout << " = ";d.print();
    cout << endl;
    cout << "Finished test " << ++i << endl;
    

    cout << "All tests successfully finished!\n";

}