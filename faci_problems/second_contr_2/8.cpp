#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>

using namespace std;

typedef long long int ll;


int main()
{
    ll a;
    cin >> a;
    vector<ll> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (fib[fib.size()-1] < a)
    {
        /* code */
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    vector<ll> elements;
    int i = fib.size()-1;
    while (i >= 0)
    {
        if (a >= fib[i])
        {
            a-= fib[i];
            elements.push_back(fib[i]);
        }
        i--;
    }
    
    for (int i = elements.size() - 1; i >= 0; i--)
    {
        cout << elements[i] << " "; 
    }
    

    
    return 0;
}