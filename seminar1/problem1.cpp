#include <iostream>
#include <vector>
#include <numeric>
#include <cstdio>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::iota;

typedef long long int ll;

vector<ll> segmtree;
vector<ll> increment_tree;


int size;
void init(int length){
    size = 1;
    while (size < length)
    {
        size <<= 1;
    }
    
    
    increment_tree = vector<ll>(2*size, 0);
    segmtree = vector<ll>(2*size, 0);
    for (int i = 0; i < size; i++)
    {
        segmtree[i+size] = i + 1;
    }
    for (int i = size - 1; i > 0; i--)
    {       
        segmtree[i] = segmtree[2*i+1] + segmtree[2*i];
    }
    
}

ll _get(ll left, ll right, ll current_left, ll current_right, int current_vertex);

ll _get(ll left, ll right, ll current_left, ll current_right, int current_vertex) {
    if (current_left >= left && current_right <= right)
    {   
        return segmtree[current_vertex] + (current_right - current_left)*increment_tree[current_vertex];

    }
    else if (current_right <= left || current_left >= right) {
        return 0;
    }
    else
    {
        increment_tree[2*current_vertex] += increment_tree[current_vertex];
        increment_tree[2*current_vertex+1] += increment_tree[current_vertex];
        segmtree[current_vertex] += increment_tree[current_vertex]*(current_right-current_left);
        increment_tree[current_vertex] = 0;
        return _get(left, right, current_left, (current_left+current_right)/2, 2*current_vertex) + 
        _get(left, right, (current_left+current_right)/2, current_right, 2*current_vertex+1); 
    }
}

ll get(ll left, ll right) {
    return _get(left, right, 0, size, 1);
}

void _increment(ll left, ll right, ll current_left, ll current_right, int current_vertex, ll increment) {
    if (current_left >= left && current_right <= right)
    {   
        increment_tree[current_vertex] += increment;
        // return segmtree[current_vertex] + (current_right - current_left)*increment_tree[current_vertex];
    }
    else if (!(current_right <= left || current_left >= right)) {
        increment_tree[2*current_vertex] += increment_tree[current_vertex];
        increment_tree[2*current_vertex+1] += increment_tree[current_vertex];
        segmtree[current_vertex] += increment_tree[current_vertex]*(current_right-current_left);
        increment_tree[current_vertex] = 0;
        _increment(left, right, current_left, (current_left+current_right)/2, 2*current_vertex, increment);
        _increment(left, right, (current_left+current_right)/2, current_right, 2*current_vertex+1, increment);
        segmtree[current_vertex] = segmtree[current_vertex*2] + segmtree[current_vertex*2+1] + increment_tree[current_vertex*2] + increment_tree[current_vertex*2+1];
    }
}

void increment(ll left, ll right, ll increment) {
    _increment(left, right, 0, size, 1, increment);
}

int main(){
    freopen("input1.txt", "r", stdin);

    int n, m;
    cout << "Введите количество людей и длину считалочки\n";
    cin >> n >> m;
    init(n);
    // for (int i = 0; i < 4*n; i++)
    // {
    //     cout << i << "\t" << segmtree[i] << endl;
    // }
    // cout << size;
    // cout << get(0, 2) << endl;
    // cout << get(10, 16) << endl;
    
    // cout << get(2, 10) << endl;
    // increment(0, 3, 2);
    // cout << get(2, 10) << endl;

    int current_n = n;
    while (current_n > 0)
    {
        int out = m % current_n;
        cout << get(out, out+1) << " номер уходит\n";
        for (int i = 0; i < n; i++)
        {
            cerr << get(i, i+1) << " ";
        }
        cerr << endl;
        
        increment(out, n, 1);
        --current_n;
    }
    
}