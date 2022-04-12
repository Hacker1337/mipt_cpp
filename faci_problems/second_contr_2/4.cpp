#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>
#include <map>

using namespace std;



int main()
{
    map<string, int> id;
id["Mon"] = 0;
id["Tue"] = 1;
id["Wed"] = 2;
id["Thu"] = 3;
id["Fri"] = 4;
id["Sat"] = 5;
id["Sun"] = 6;
    map<int, int> count;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        count[id[name]] += 1;
    }
    string days[7] = {"Mon",  "Tue",  "Wed",  "Thu",  "Fri",  "Sat",  "Sun"};

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j < count[i]; ++j)
        {
            cout << days[i] << " ";
        }
    }
    

    return 0;
}