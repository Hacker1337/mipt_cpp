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
    ll a, b;
    cin >> a >> b;

    vector<bool> sqare(b-a+1, false);
    vector<bool> cube(b-a+1, false);
    for (ll x = 1; x < sqrt(b)+10; x++)
    {
        ll x2 = x*x;
        ll x3 = x2*x;
        for (ll y = 1; y < sqrt(b)+10; ++y)
        {
            if (x == y)
            {
                continue;
            }
            
            ll y2 = y*y;
            ll y3 = y2*y;
            if (x2+y2 <= b) {
                if (x2+y2 >= a)
                    sqare[x2+y2-a] = true;
                if (x3+y3 <= b && x3+y3 >= a)
                {
                    cube[x3+y3-a] = true;
                }
                
            }
            else
            {
                break;
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        if (sqare[i-a] && cube[i-a])
        {
            cout << i << endl;
        }
        
    }
    
    

    
    return 0;
}