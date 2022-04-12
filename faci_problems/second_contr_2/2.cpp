#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>

using namespace std;



int main()
{
    string s;
    cin>> s;
    int sum = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sum += ((i%2)*2-1)*(s[i]-'0');
    }
    if (sum % 11) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    
    return 0;
}