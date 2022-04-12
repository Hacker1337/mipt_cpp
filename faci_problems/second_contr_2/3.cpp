#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>
#include <map>

using namespace std;



int main()
{
    cout << fixed << setprecision(3);
    int n;
    cin >> n;
    multimap<float, string> rate;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int k;
        cin >> k;
        float sum = 0;
        for (int i = 0; i < k; i++)
        {
            int t;
            cin >> t;
            sum += t;
        }
        rate.insert(make_pair(sum/k, name));
        
    }
    for (auto p = rate.rbegin(); p != rate.rend(); p++) {
        cout << p->second << " " << p->first << "\n";
    }
    
    
    return 0;
}