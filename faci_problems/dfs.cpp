#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::min;
#include <math.h>
#include <algorithm>
#include <vector>
using std::vector;

struct edge{
    int x;
    int cost;
};

vector<vector<edge>> graph;
vector<int> dist;

void dfs(int start) {
    for (auto e: graph[start]) {
        if (dist[start]+e.cost < dist[e.x])
        {
            dist[e.x] = dist[start]+e.cost;
            dfs(e.x);
        }
    }
}

int main(){
    int n, m, M;
    cin >> n >> m;
    graph = vector<vector<edge>>(n);
    dist = vector<int>(n, 1e9);
    for (size_t i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a-1].push_back({b-1, cost});
        graph[b-1].push_back({a-1, cost});
    }
    dist[0] = 0;
    dfs(0);
    cin >> M;
    if (dist[n-1] <= M)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}