#include "simulater.h"
#include <random>
#include <algorithm>
#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output50.txt", "w", stdout);


    int width, hight, iterNumber;
    hight = 50;

    width = 1;
    iterNumber = 1000;
    

    vector<vector<bool>> Field(hight, vector<bool>(width));
    vector<pair<int, int>> order;
    for (int i = 0; i < hight; i++)
    {
        for (int j = 0; j < width; j++)
        {
            order.push_back({i, j});
        }   
    }
    
    shuffle (order.begin(), order.end(), std::default_random_engine(time(0)));

    
    int disloc_step = 1;
    int disloc_number = 0;

    while (disloc_number + disloc_step <= order.size()) {
        cout << (0.0 + disloc_number)/order.size() << '\t';
        for (int i = 0; i < iterNumber; ++i) {
            cout << modelingTime(Field) << "\t";
        }
        cout << '\n';

        // increasing disloc number
        for (int disloc = disloc_number; disloc < disloc_number + disloc_step; disloc++)
        {
            Field[order[disloc].first][order[disloc].second] = 1;
        }
        disloc_number += disloc_step;
        
    } 
    
  
    return 0;
}
