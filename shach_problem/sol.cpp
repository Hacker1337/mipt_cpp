#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <assert.h>


using namespace std;

template<typename T>
using v = vector<T>;

const int inf = 1e3;

template<typename T>
class DP {
    int dim;
    int size;
    T* array;
    T default_value;
    T border_value;
public:
    DP(T values, T border_value, int dim=4, int size=8): border_value(border_value), dim(dim), size(size) {
        array = new T[(int)pow(size, dim)];
        for (int i = 0; i < pow(size, dim); i++)
        {
            array[i] = values;
        }
        
    }

    T get(int i, int j, int k, int l) {
        if (i >= size || j >= size || k >= size || l >= size || 
        i < 0 || j < 0 || k < 0 || l < 0) {
            // throw std::out_of_range("Wrong indicies");
            return border_value;
        }
        return array[l + size*(k + size*(j + size*i))];
    }
    T& set(int i, int j, int k, int l) {
        if (i >= size || j >= size || k >= size || l >= size || 
        i < 0 || j < 0 || k < 0 || l < 0) {
            throw std::out_of_range("Wrong indicies");
        }
        return array[l + size*(k + size*(j + size*i))];
    }

    
    ~DP(){
        delete[] array;
    }
};

const int size = 8;


void print_desk(int i, int j, int k, int l) {
    vector<vector<char>> field(size, vector<char>(size, '#'));
    field[2][2] = 'k';
    field[i][j] = 'k';
    field[k][l] = 'f';

    cout << "  ";
    for (int a = 0; a < size; a++)
    {
        cout << a << " ";
    }
    cout << endl;
    for (int b = 0; b < size; b++)
    {
        cout << b << " ";
        for (int a = 0; a < size; a++)
        {
            cout << field[b][a] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    

}

int main(){
    // freopen("input.txt", "r", stdin);

    // v<v<v<v<int>>>> dpwhite = v<v<v<v<int>>>>(size, v<v<v<int>>>(size, v<v<int>>(size, v<int>(size, inf))));
    // v<v<v<v<int>>>> dpblack = v<v<v<v<int>>>>(size, v<v<v<int>>>(size, v<v<int>>(size, v<int>(size, inf))));
    DP<int> dpwhite(inf, -1);
    DP<int> dpblack(inf, -1);
    DP<pair<int, int>> fers_steps({-1, -1}, {-1, -1}); // куда должен походить ферзь из этой позиции
    DP<pair<int, int>> king_steps({-1, -1}, {-1, -1}); // куда должен походить король из этой позиции

    // начальные значения
    
    for (int k = 0; k < size; k++)
    {
        for (int l = 0; l < size; l++)
        {   
            // бьется королем
            for (int x1 = -1; x1 < 2; x1++)
            {
                for (int x2 = -1; x2 < 2; x2++)
                {
                    dpblack.set(2+x1, 2+x2, k, l) = -1;
                } 
            }
            // бьется ферзем
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t1++) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t1--) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t2++) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t2--) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1++, t2++) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1--, t2--) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1++, t2--) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1--, t2++) {
                if (t1==k && t2==l)
                    continue;
                dpblack.set(t1, t2, k, l) = -1;
            }
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 2 && j == 2)
            {
                continue;
            }
            dpwhite.set(i, j, i, j) = -2;   // ферзь съел короля
        }
        
    }
    


    // int k = 5;
    // int l = 5;
    // for (int i = 0; i < size; i++)
    // {for (int j = 0; j < size; j++){
    //     // cout << dpblack.get(i, j, k, l) << " ";
    //     cout << dpblack.get(i, j, k, l) << "\t";
    // }
    // cout << endl;
    // }


    
    for (int step_num = -1; step_num < 26; step_num++)
    {
        // ходит черный король

        for (int i = 0; i < size; i++)
        {for (int j = 0; j < size; j++)
        {for (int k = 0; k < size; k++)
        {for (int l = 0; l < size; l++){
            // if (i == 1 && j == 5 && k == 3 && l == 6) {
            //     // cout << "it is it\n";
            // }
            if (k == 2 && l == 2)
            {
                if (dpwhite.get(i, j, k, l) != inf)
                {
                    cerr << "Error. Fers can eat his king" << endl;
                }
                continue;
            }
            if (i == k && j == l)   // ферзь съел короля - тут -2 мат был 2 хода назад
            {
                if (dpwhite.get(i, j, k, l) != -2) {
                    // cerr << "Error. fers has eaten king wrongly" << endl;
                }
                continue;
            }
            // if (dpwhite.get(i,j,k,l) != inf)
            //     continue;

            
            dpwhite.set(i,j,k,l) = -10;
            for (int x1 = -1; x1 < 2; x1++)
            {
                for (int x2 = -1; x2 < 2; x2++)
                {
                    if (x1 != 0 || x2 != 0) {
                        if (dpblack.get(i+x1, j+x2, k, l)+1 > dpwhite.get(i,j,k,l) ) {
                            dpwhite.set(i,j,k,l) = min(inf, max(dpblack.get(i+x1, j+x2, k, l)+1, dpwhite.get(i,j,k,l)));
                            king_steps.set(i, j, k, l) = {i+x1, j+x2};
                        }
                    }
                }
            }            
            if (dpwhite.get(i,j,k,l) == 0) {   // королю некуда идит
            // если король может оставаться на месте, тогда пат
                if (dpblack.get(i, j, k, l) != -1) {    
                    dpwhite.set(i,j,k,l) = inf;
                }
            } 
        }}}}


        // ходит белый ферзь
        for (int i = 0; i < size; i++)
        {for (int j = 0; j < size; j++)
        {for (int k = 0; k < size; k++)
        {for (int l = 0; l < size; l++){
            if (i == 2 && j == 2)
            {
                if (dpblack.get(i, j, k, l) != -1)
                {
                    // cerr << "Error. Wrong value, when black king has eaten white one" << endl;
                    // cerr << i << " " << j << " " << k << " " << l << " " << dpblack.get(i, j, k, l) << endl;
                }
                
                continue;
            }
            
            // if (dpblack.get(i, j, k, l) != inf)
            // {
            //     continue;
            // }
            if (dpblack.get(i, j, k, l) == -1)  // тут король черный бьется
            {
                continue;
            }
            
            if (i == k && j == l) {
                if (dpblack.get(i, j, k, l) != inf) {
                    // cerr << "Error. King has eaten fers and didn't win" << endl;
                    // cerr << i << " " << j << " " << k << " " << l << " " << dpblack.get(i, j, k, l) << endl;                    
                }
                continue;
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t1++) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }            
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t1--) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t2++) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2); t2--) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1++, t2++) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1--, t2--) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1++, t2--) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
            for (int t1(k), t2(l); 0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2);t1--, t2++) {
                if (t1==k && t2==l)
                    continue;
                if (1 + dpwhite.get(i, j, t1, t2) < dpblack.get(i, j, k, l)) {
                    dpblack.set(i, j, k, l) = 1 + dpwhite.get(i, j, t1, t2);    
                    fers_steps.set(i, j, k, l) = {t1, t2};
                }
            }
        }}}}

        
    }
    

    int max_steps = -2;

    for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
    for (int k = 0; k < size; k++){
    for (int l = 0; l < size; l++){
        if (k == 2 && l == 2)
            continue;
        if (i == k && j == l)
            continue;
        // if (dpblack.get(i, j, k, l) > max_steps) {
        //     cout << i << " " << j << " " << k << " " << l << " is bed pos. Steps = " << dpblack.get(i, j, k, l) << endl;
        // }
        if (dpblack.get(i, j, k, l) != inf)
        {
            max_steps = max(max_steps, dpblack.get(i, j, k, l));     
        }
        // int s = 10;
        // if (dpwhite.get(i, j, k, l) == s)
        // {
        //     cout << i << " " << j << " " << k << " " << l << " is mat in " << s << " steps" << endl;   
        // }
                 
        // cout << dpblack.get(i, j, k, l) << " ";
        // cout << dpwhite.get(i, j, k, l) << " ";
    }
    // cout << endl;
    }}}


    // for (int k = 0; k < size; k++){
    // for (int l = 0; l < size; l++){
    //     int i = 7;
    //     int j = 7;
    //     cout << fers_steps.get(i, j, k, l).first << " ";
    //     cout << fers_steps.get(i, j, k, l).second << "\t";
    //        // вывод победного хода
    // }
    // cout << endl;
    // }
    // cout << endl;


    // int i = 5;
    // int j = 6;
    // for (int k = 0; k < size; k++){
    // for (int l = 0; l < size; l++){
    //     // cout << dpblack.get(i, j, k, l) << "\t";
    //     cout << dpwhite.get(i, j, k, l) << "\t";
    // }
    // cout << endl;
    // }
    // cout << endl;


    // for (int i = 0; i < size; i++){
    // for (int j = 0; j < size; j++){
    //     int k = 2;
    //     int l = 0;
    //     cout << dpblack.get(i, j, k, l) << " ";
    //     // cout << dpwhite.get(i, j, k, l) << " ";
    // }
    // cout << endl;
    // }

    

    cout << "Mat is after maximum " << (max_steps+1)/2 << " steps\n";
    int x1, y1, x2, y2;



    // cout << "Enter king position and fers position (1-8 1-8 1-8 1-8), to find out number of steps\n";
    // cin >> x1 >> y1 >> x2 >> y2;7 7 0 0
    
    // cout << endl;
    // cout << (dpblack.get(x1-1, y1-1, x2-1, y2-1)+1)/2 << endl;


    // cout << "Enter king and fers position (0-7 0-7) to find out the best fers step\n";
    // while (cin >> x1 >> y1 >> x2 >> y2) {
    //     cout << fers_steps.get(x1, y1, x2, y2).first << " " << fers_steps.get(x1, y1, x2, y2).second << endl;
    // }
    // while (cin >> x1 >> y1 >> x2 >> y2) {
    //     cout << "Enter king and fers position (0-7 0-7) to find out the best king step\n";
    //     cout << king_steps.get(x1, y1, x2, y2).first << " " << king_steps.get(x1, y1, x2, y2).second << endl;
    //     cout << dpwhite.get(x1, y1, x2, y2) << " steps are there" << endl;

    //     cout << "Enter king and fers position (0-7 0-7) to find out the best fers step\n";
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     cout << fers_steps.get(x1, y1, x2, y2).first << " " << fers_steps.get(x1, y1, x2, y2).second << endl;
    //     cout << dpwhite.get(x1, y1, x2, y2) << " steps are there" << endl;
    // }



    // game modeling
    cout << "enter initial position (0-7 0-7 0-7 0-7)\n";

    cin >> x1 >> y1 >> x2 >> y2;

    int counter_t = 0;
    while (counter_t < 300)
    {
        print_desk(y1, x1, y2, x2); 
        // cout << dpwhite.get(x1, y1, x2, y2) << " steps are there" << endl;
        cout << "enter fers step or \"-1\" for autostep\n";
        int t;
        cin >> t;
        if (t == -1) {
            cout << "fers goes to " << fers_steps.get(x1, y1, x2, y2).first << " " << fers_steps.get(x1, y1, x2, y2).second << endl;
            int t1 = fers_steps.get(x1, y1, x2, y2).first;
            int t2 = fers_steps.get(x1, y1, x2, y2).second;        
            x2 = t1;
            y2 = t2;
            print_desk(y1, x1, y2, x2);            
        }
        else {
            x2 = t;
            cin >> y2;
            cout << dpblack.get(x1, y1, x2, y2) << " steps are there" << endl;
        }
        print_desk(y1, x1, y2, x2);
        cout << "enter king step or \"-1\" for autostep\n";
        cin >> t;
        if (t == -1) {
            cout << "king goes to " << king_steps.get(x1, y1, x2, y2).first << " " << king_steps.get(x1, y1, x2, y2).second << endl;
            cout << dpwhite.get(x1, y1, x2, y2) << " steps are there" << endl;
            int t1 = king_steps.get(x1, y1, x2, y2).first;
            int t2 = king_steps.get(x1, y1, x2, y2).second;        
            x2 = t1;
            y2 = t2;
        }
        else{
            x1 = t;
            cin >> y1;
            cout << dpwhite.get(x1, y1, x2, y2) << " steps are there" << endl;

        }
        // cout << dpblack.get(x1, y1, x2, y2) << " steps are there" << endl;   
        counter_t+= 2;
    }

    

}