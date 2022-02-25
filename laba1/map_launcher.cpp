#include "simulater.h"
#include <random>
#include <algorithm>

int main() {

    int width, hight, iterNumber;
    cin >> hight >> width;
    cin >> iterNumber;

    vector<vector<bool>> testField(hight, vector<bool>(width));
    vector<pair<int, int>> order;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            order.push_back({i, j});
        }
        
    }
    
    // testField[i0][j0] = 1;
    shuffle (order.begin(), order.end(), std::default_random_engine(42));

    
    // for

    for (int i = 0; i < iterNumber; ++i) {
        cout << modelingTime(testField) << "\n";
    }
    return 0;
}
