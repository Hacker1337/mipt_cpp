#include <iostream>
#include <cassert>
#include <algorithm>

#include "grids.cpp"
using namespace std;


class Shout_on_distruct {
    int a;

    ~Shout_on_distruct() {
        cout << "I am distructed!\n";
    }
};

int main() {
    int N = 10;

    void* raw_mem = operator new(N*sizeof(Shout_on_distruct));
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
}