#include <random>
#include <algorithm>


#include <vector>
#include <iostream>
#include <chrono> 
using  std::vector ;
using namespace std;

template<typename T>
bool sorted(vector<T> a) {
    bool sort = true;
    for (size_t i = 0; i < a.size()-1; i++)
    {
        if (a[i] > a[i+1]) {
            sort = false;
            break;
        }
    }
    return sort;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (! sorted(a))
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        shuffle (a.begin(), a.end(), std::default_random_engine(seed));
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    
    
}
