#include "simulater.h"


int main() {

    int width, hight, i0, j0, iterNumber;
    cin >> hight >> width;
    cin >> i0 >> j0 >> iterNumber;
    j0 = 0;
    width = 1;

    vector<vector<bool>> testField(hight, vector<bool>(width));
    
    testField[i0][j0] = 1;
    
    for (int i = 0; i < iterNumber; ++i) {
        cout << modelingTime(testField) << "\n";
    }
    return 0;
}
