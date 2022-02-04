#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int n;
    cin >> n;
    int null_numbers = 0;
    int one_numbers = 0;
    while (n != 0)
    {
        if (n%2) {
            one_numbers++;
        }
        else {
            null_numbers++;
        }
        n >>= 1;
    }

    for (int i = 0; i < one_numbers; i++)
    {
        cout << 1;
    }
    for (int i = 0; i < null_numbers; i++)
    {
        cout << 0;
    }
    
    // cout << one_numbers << endl;
    
}