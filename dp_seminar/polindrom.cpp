#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <string>
#include <map>

using namespace std;



int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    vector<vector<pair<int, int>>> prev(n+1, vector<pair<int, int>>(n+1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            dp[i][j] = dp[i-1][j-1];
            prev[i][j] = {i-1, j-1};
            for (int p = i - 1; p >= 0 && dp[p][j-1] >= dp[i][j]; p--)
            {
                if (s[p] == s[n-j]) {
                    prev[i][j] = {p, j-1};
                    dp[i][j] = dp[p][j-1] + 1;
                }
            }

            for (int q = j - 1; dp[i-1][q] >= dp[i][j]; q--)
            {
                if (s[i-1] == s[n-1-q])
                {
                    prev[i][j] = {i-1, q};
                    dp[i][j] = dp[i-1][q]+1;
                }
            }
        }
    }
    pair<int, int> maxpos = {0, 0};
    int max_pol = -1;
    for (int i = 1; i < n; i++)
    {
        if (dp[i][n-i] >= max_pol)
        {
            maxpos = {i, n-i};
            max_pol = dp[i][n-i];
        }
        
    }
    cout << max_pol << " is max len\n";
    cout << maxpos.first << " " << maxpos.second << endl;
    vector<char> result;
    while (maxpos.first > 0 && maxpos.second > 0)
    {   
        maxpos = prev[maxpos.first][maxpos.second];
        result.push_back(s[maxpos.first]);
    }
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    
    
    
    
    
    return 0;
}