//
// Created by Амир on 18.02.2022.
//

#include "simulater.h"
#include <ctime>
#include <random>

std::mt19937 gen(1*time(0));

vector<vector<bool>> field;

bool isAlive(int i, int j) {
    return (i != 0 && i != field.size()-1) && !(field[i+1][j] || field[i-1][j]);
}
bool isAlive(pair<int, int> pair) {
    return isAlive(pair.first, pair.second);
}

pair<int, int> move(pair<int, int> pos) {
    int dist = (gen()%2)*2-1;
    // bool dir = gen()%2;
    return {pos.first + dist, pos.second};
}

void printField(){
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[0].size(); ++j) {
            if (field[i][j]) {
                cout << "#";
            }
            else
                cout << '.';
        }
        cout << endl;
    }
    for (int i = 0; i < field[0].size(); ++i) {
        cout << '_';
    }
    cout << endl;

}
pair<int, int> null = {-1, -1};

int modelingTime(const vector<vector<bool>> initialMap) {

    field = initialMap;
    int lifeTime = 0;
    vector<pair<int, int>> aliveCells;
    for (int i = 1; i < field.size()-1; ++i) {
        for (int j = 0; j < field[0].size(); ++j) {
            if (field[i][j] && isAlive(i, j)) {
                aliveCells.emplace_back(i, j);
            }
        }
    }
    while (!aliveCells.empty()) {
        vector<pair<int, int>> newAlive;
        for (int i = 0; i < aliveCells.size(); ++i) {
            if (!isAlive(aliveCells[i])) {
                aliveCells[i] = null;
            }
            else {
                newAlive.push_back(move(aliveCells[i]));
            }
        }
        int j = 0;
        for (int i = 0; i < aliveCells.size(); ++i) {
            if (aliveCells[i] == null)
                continue;
            if (field[newAlive[j].first][newAlive[j].second] == 0) {
                field[newAlive[j].first][newAlive[j].second] = 1;
                field[aliveCells[i].first][aliveCells[i].second] = 0;
            }
            j++;
        }
        ++lifeTime;
        aliveCells = newAlive;
//        printField();
    }

    return lifeTime;
}