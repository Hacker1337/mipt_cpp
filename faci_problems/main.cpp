#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::min;
#include <math.h>
#include <algorithm>

struct pixel{
    int x;
    int y;
    int brightness;
    int dist2() {
        return x*x+y*y;
    }
};
struct pixels{
    int x;
    int y;
    int brightness;
    int dist2() {
        return x*x+y*y;
    }
    int count;
};

bool coord_ord(pixel a, pixel b) {
    if (a.x < b.x) {
        return true;
    }
    if (a.x > b.x)
    {
        return false;
    }
    
    if (a.y <= b.y)
    {
        return true;
    }
    return false;
}
bool comp(pixels a, pixels b) {
    if (a.brightness > b.brightness) {
        return true;
    }
    if (a.brightness < b.brightness)
    {
        return false;
    }
    if (a.count > b.count) {
        return true;
    }
    if (a.count < b.count)
    {
        return false;
    }
    if (a.dist2() < b.dist2()) {
        return true;
    }
    // if (a.dist2() > b.dist2())
    // {
        return false;
    // }
    

    
}

int main() {
    // решение через сортировку, потом будет через set из структур с количеством повторов

    int n;
    cin >> n;
    pixel* a = new pixel[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, b;
        cin >> x >> y >> b;
        a[i] = {x, y, b};
        if (a[i].brightness < 10 && a[i].dist2() > 100*100)
        {
            n--;
            i--;
        }   
    }
    if (n == 0)
    {
        delete[] a;
        return 0;
    }
    
    std::sort(a, a+n, coord_ord);
    
    
    pixels* result = new pixels[n];
    int result_size = 1;
    result[0] = {a[0].x, a[0].y, a[0].brightness, 1};
    for (size_t i = 1; i < n; i++)
    {
        if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) {
            result[result_size-1].count++;
        }
        else {
            result[result_size] = {a[i].x, a[i].y, a[i].brightness, 1};
            result_size++;
        }
    }
    std::sort(result, result+result_size, comp);

    for (size_t i = 0; i < result_size; i++)
    {
        cout << result[i].x << " " << result[i].y << " " << result[i].brightness << endl;

    }
    


    delete[] result;
    delete[] a;
    return 0;
}