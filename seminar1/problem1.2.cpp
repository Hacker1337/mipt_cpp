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


int main(){
    // freopen("input1.txt", "r", stdin);

    ll n, m;
    cout << "Введите количество людей и длину считалочки\n";
    cin >> n >> m;
    vector<ll> order(n);
    iota(order.begin(), order.end(), 1);

    ll current_n = n;
    while (current_n > 3) {
        ll out = (m-1)%current_n;
        if (order[out] > 0)
            order[out] = -1;
        else
            --order[out];
        --current_n;
        
    }
    while (current_n > 0) {
        ll index = 0;
        ll number = 0;
        ll out = (m - 1)%current_n;
        while (out > number || order[index] < 0)
        {
            if (order[index] < 0)
            {
                number += order[index];
            }
            ++index;
            ++number;
        }

        cout << order[index] << " номер уходит\n";
        order[index] = -1;
        --current_n;
    }
}