#include <iostream>
#include <vector>

using namespace std;

struct window{
    int x1, x2, y1, y2;
};

bool intersept(int a1, int a2, int b1, int b2) {
    return !(b1 >= a2 || a1 >= b2);
}
bool possible_windows(window a, window b) {
    return !(intersept(a.x1, a.x2, b.x1, b.x2) && intersept(a.y1, a.y2, b.y1, b.y2));
}

int main() {
    string a, b; 
    cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1));
    vector<vector<int>> source(a.size()+1, vector<int>(b.size()+1)); // 0 - from diagonal dir, 1 - from first coordinate increase, 2 from second

    for (size_t i = 1; i < a.size()+1; i++)
    {
        for (size_t j = 1; j < b.size()+1; j++)
        {
            if (a[i-1] == b[j-1])
            {
                source[i][j] = 0;
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                source[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j-1];
                source[i][j] = 2;
            }            
        }
    }
    vector<char> answer;
    int i = a.size();
    int j = b.size();
    while (j != 0 && i != 0)
    {
        if (source[i][j] == 0)
        {
            answer.push_back(a[i-1]);
            --i;
            --j;
        }
        else if (source[i][j] == 1) {
            --i;
        }
        else {
            --j;
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        cout << answer[i];
    }
    
    
    

       

    return 0;
}
/*


BXMJYAUZ
CMZJAWXU
      

*/