#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <algorithm>


int main() {

    long long int n;
    cin >> n;
    long long int res = 0;
    while (n > 0)
    {
        n >>= 1;
        res += n;
    }

    cout << res;
    


    return 0;
}