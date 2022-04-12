#include <stdint.h>

bool get(int i) {
    return get_results(i%360);
}

bool increase(int i) {
    return get(i+1) > get(i);
}
bool maximum_is_between(int left, int right) {
    // это индексы по модулю, но в правльном порядке
    if (increase(left) && !increase(right)) 
    {
        // максимум точно между
        return true;
    }
    if (increase(left) && increase(right) && (get(right) < get(left)))
    {
        /* code */
    }
    еlse 
    return false
    
}

void detect() {
    // идея в том, чтобы искать бинарным поиском. Если в двух точках функция возрастает и у более правого угла значение больше, что и между 
    // функция возрастает, иначе было бы два промежутка убывания: внутри и снаружи
    // тут бинарный поиск
}


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
int main() {
    detect();
    return 0;
}