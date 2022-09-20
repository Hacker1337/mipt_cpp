#include <stdint.h>

uint32_t get_results(uint32_t channel)
{
    static uint32_t calls = 0;
    calls++;
    if (calls > 25) return static_cast<uint32_t>(-1);

    static uint32_t min = 10, max = 255760;
    static uint32_t min_channel = 50, max_channel = 250;
    static uint32_t zero = 100000;

    if (channel <= min_channel)
        return static_cast<uint32_t>(zero - channel*((double)zero - min)/min_channel);
    if (channel <= max_channel)
        return static_cast<uint32_t>(min + ((double)channel - min_channel)*((double)max - min)/((double)max_channel - min_channel));
    if (channel <= 360)
        return static_cast<uint32_t>(max - ((double)channel - max_channel)*((double)max - zero)/((double)360 - max_channel));
    return static_cast<uint32_t>(-1);
}

#include <iostream>
using namespace std;

int get(int i) {
    return get_results(i%360);
}

void detect() {
    // идея в том, чтобы искать бинарным поиском. Если в двух точках функция возрастает и у более правого угла значение больше, что и между 
    // функция возрастает, иначе было бы два промежутка убывания: внутри и снаружи
    // тут бинарный поиск
    int left = 0;
    int right = 359;
    int left_val = get(left);
    while (right-left > 1)
    {
        int mid = (right + left)/2;
        int a = get(mid);
        int b = get(mid+1);
        if ((a < b) && left_val < a) {
            left = mid+1;
            int left_val = b;
        }
        else {
            right = mid+1;
        }
        // if (maximum_is_between(left, mid)) {
        //     right = mid;
        // }
        // else {
        //     left = mid;
        // }
    }
    if (get(right) > get(left)) {
        cout << get(right);
        cout << " ";
        cout << right;
    }
    else {
        cout << get(left);
        cout << " ";
        cout << left;
    }
    
}

int main() {
    // cout << get(246) << endl;
    // cout << get(247) << endl;
    // cout << get(257) << endl;
    // cout << get(258) << endl;
    // cout << increase(257) << endl;
    // cout << increase(246) << endl;
    // cout << get(4) << endl;
    // cout << get(250) << endl;
    detect();
    return 0;
}