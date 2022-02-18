#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::iota;
using namespace std;

typedef long long int ll;

ll space(vector<std::pair<ll, ll>> vertex) {
    ll answer = 0;
    for (int i = 0; i < vertex.size(); i++)
    {
        answer += vertex[i].first*vertex[(i+1)%vertex.size()].second;
        answer -= vertex[(i+1)%vertex.size()].first*vertex[i].second;
    }
    return abs(answer);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("answer.txt", "w", stdout);

    vector<std::pair<ll, ll>> points;
    ll a, b;
    while (cin >> a)
    {
        cin >> b;
        points.push_back({a, b});
    }
    sort(points.begin(), points.end());

    for (auto &&i : points)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    

}