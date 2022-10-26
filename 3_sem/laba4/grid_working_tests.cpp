#include <iostream>
#include <cassert>
#include <algorithm>

#include "grids.cpp"

int main() {
    Grid<float> g(3, 2);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    Grid<float> g1(1.0f);
    assert(g1.get_x_size() == 1);
    assert(g1.get_y_size() == 1);

    g1 = g;
    assert(3 == g1.get_y_size());
    assert(2 == g1.get_x_size());
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());
    g1 = std::move(g);
    assert(3 == g1.get_y_size());
    assert(2 == g1.get_x_size());
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    Grid<float> g2(2, 2, 1.0);
    assert(g2(1, 1) == 1.0);
    // test [] operator
    assert(g2[1][1] == 1.0);


    Grid<float, 3> const g3(2, 3, 4, 1.0f);
    assert(2 == g3.get_z_size());
    assert(1.0f == g3(0, 1, 1));
    assert(1.0f == g3(1, 1, 1));
    Grid<float, 2> g4(2, 5, 2.0f);

    assert (2.0f == g4(1, 1));

   g4 = g3[1];
   assert (1.0f == g4(1, 1));

    std::cout << "Everything works fine!\n";
}