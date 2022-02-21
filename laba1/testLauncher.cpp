#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-bool-literals"
//
// Created by Амир on 18.02.2022.
//
#include "simulater.h"



int main() {

    vector<vector<bool>> testField(10, vector<bool>(10));

    testField[4][7] = 1;
    testField[6][1] = 1;
    testField[1][6] = 1;
    testField[5][3] = 1;

    for (int i = 0; i < 500; ++i) {
        cout << modelingTime(testField) << ", \n";
    }
    return 0;
}
#pragma clang diagnostic pop