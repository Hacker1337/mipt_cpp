#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>



map<string, pair<int, vector<pair<string, int>>>> recipe;  //если рецепта нет, нет такого элемента
bool ok;
void push(string element, int n, map<string, int>& invent) {
    if (!ok) {
        return;
    }
    int lack = max(0, n-invent[element]);
    if (recipe.count(element) == 0)
    {
        if (lack > 0)
        {
            ok = false;
        }
        else {
            invent[element] -= n;
        }
        return;
    }
    
    int craftNum = (lack/recipe[element].first) + (bool)lack%recipe[element].first;
    invent[element] += craftNum*recipe[element].first - n;
    if (craftNum > 0) {
        for(auto ingr: recipe[element].second) {
            push(ingr.first, craftNum*ingr.second, invent);
        }
    }
}

bool check_possibility(map<string, int> invent, int mid, string element) {
    ok = true;
    push(element, mid, invent);
    return ok;
}


int main() {

    
    int N;
    cin >> N;   //кол-во рецептов

    for (int i = 0; i < N; i++)
    {
        string filename;
        cin >> filename;
    
        ifstream fin;
        fin.open(filename);

        string result;
        int resNum;
        fin >> result;
        fin >> resNum;
        vector<pair<string, int>> craft;
        string name;
        int count;
        while (fin >> name)
        {
            fin >> count;
            craft.push_back(make_pair(name, count));
        }
        if (recipe.count(result))
        {
            throw "I can't work with multiple recipes";
        }
        recipe[result] = make_pair(resNum, craft);
        fin.close();
    }


    int hasNum;
    cin >> hasNum;
    map<string, int> invent;
    int sumInvent = 0;
    for (int i = 0; i < hasNum; i++)
    {
        string name;
        int count; 
        cin >> name;
        cin >> count;
        sumInvent += count;
        invent[name] = count;
    }
    string mainElement;
    cin >> mainElement;

    int left = 0;
    int right = sumInvent+1;
    while (right - left > 1)
    {
        int mid = (right + left)/2;
        if (check_possibility(invent, mid, mainElement)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    cout << left;
    



    
    return 0;
}

/*

3
recipe0.txt
recipe1.txt
recipe2.txt
2
tonga 8
kvanga 2
kuzyablik

*/