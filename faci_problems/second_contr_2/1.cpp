#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

// template<typename T>
double sum(vector<double>::iterator a, vector<double>::iterator b) {
    if (b - a == 1) {
        return *a;
    }
    else {
        vector<double>::iterator mid = a + (b - a)/2;
        return sum(a, mid) + sum(mid, b);
    }
}

int main()
{
    cout << fixed << setprecision(4);
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    
    double average = sum(a.begin(), a.end())/n;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] - average << " ";
    }

    

    return 0;
}