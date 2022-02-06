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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "r", stdout);

    ll n, m;
    ll winners = 3;    // сколько выживших отслеживать
    cout << "Введите количество людей и длину считалочки\n";
    cin >> n >> m;
    vector<int> alive(n, 1);
    // iota(order.begin(), order.end(), 1);

    ll current_n = n;
    while (current_n > winners) {
        ll out = (m-1)%current_n;   // выбывает в 0-нумерации
        --alive[out];
        --current_n;
        
    }
    while (current_n > 0) {
        ll index = 0;
        ll number = 0;      // количество живых людей с индексом меньше index
        ll out = (m - 1)%current_n;     // выбывает в 0-нумерации
        while (out + 1 > number)    // остановка, когда количество живых людей с меньшим номером == номеру выбывающего в 1-нумерации
        {
            number += alive[index];
            ++index;
        }

        cout << index << " номер уходит\n";
        --alive[out];
        --current_n;
    }
}