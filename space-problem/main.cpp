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

struct point{
    int x, y;
    int i, vneib, hneib;    // index, index of vertical neighbour, index of horisontal neighbour
};
bool cmp_y(point a, point b) {
    return a.y < b.y;
}
bool cmp_x(point a, point b) {
    return a.x < b.x;
}
bool cmp_i(point a, point b) {
    return a.i < b.i;
}

int main(){
    freopen("TEST_SQ.DAT", "r", stdin);
    // freopen("simple_input.txt", "r", stdin);
    // freopen("answer.txt", "w", stdout);

    vector<std::pair<ll, ll>> points;
    int a, b;
    
    vector<point> vertex;
    int i = 0;

    while (cin >> a)
    {
        cin >> b;
        // points.push_back({a, b});
        vertex.push_back({a, b, i++, -1, -1});
    }
    stable_sort(vertex.begin(), vertex.end(), cmp_y);
    stable_sort(vertex.begin(), vertex.end(), cmp_x);

    for (auto &&i : vertex)
    {
        cerr << i.x << " " << i.y << endl;
    }
    cerr << "\n\n";

    for (int i = 0; i < vertex.size(); i+=2)
    {
        vertex[i].vneib = vertex[i+1].i;
        vertex[i+1].vneib = vertex[i].i;
    }
    stable_sort(vertex.begin(), vertex.end(), cmp_y);

    for (auto &&i : vertex)
    {
        cerr << i.x << " " << i.y << endl;
    }
    cerr << "\n\n";

    for (int i = 0; i < vertex.size(); i+=2)
    {
        vertex[i].hneib = vertex[i+1].i;
        vertex[i+1].hneib = vertex[i].i;
    }

    sort(vertex.begin(), vertex.end(), cmp_i);
    
    int current_i = 0;
    int pi = 0;
    do {
        points.push_back({vertex[current_i].x, vertex[current_i].y });
        current_i = vertex[current_i].hneib;
        points.push_back({vertex[current_i].x, vertex[current_i].y });
        current_i = vertex[current_i].vneib;
    } while (current_i != 0);
    

    for (auto &&i : points)
    {
        cout << i.first << " " << i.second << endl;
    }

    points.push_back(points[0]);
    int space = 0;
    for (int i = 0; i < points.size()-1; i++)
    {
        space += points[i].first*points[i+1].second - points[i+1].first*points[i].second;
    }
    space/=2;
    cout << "Space of the figure is " << abs(space) << endl;

    

}