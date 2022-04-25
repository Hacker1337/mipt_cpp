#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdexcept>


using namespace std;

template<typename T>
using v = vector<T>;

const int inf = 1e3;

class DP {
    int dim;
    int size;
    int* array;
public:
    DP(int dim=4, int size=8, int values=inf): dim(dim), size(size) {
        array = new int[(int)pow(size, dim)];
        for (int i = 0; i < pow(size, dim); i++)
        {
            array[i] = values;
        }
        
    }

    int get(int i, int j, int k, int l) {
        if (i >= size || j >= size || k >= size || l >= size || 
        i < 0 || j < 0 || k < 0 || l < 0) {
            // throw std::out_of_range("Wrong indicies");
            return 0;
        }
        return array[l + size*(k + size*(j + size*i))];
    }
    int& set(int i, int j, int k, int l) {
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

int main(){
    freopen("input.txt", "r", stdin);

    const int size = 8;
    // v<v<v<v<int>>>> dpwhite = v<v<v<v<int>>>>(size, v<v<v<int>>>(size, v<v<int>>(size, v<int>(size, inf))));
    // v<v<v<v<int>>>> dpblack = v<v<v<v<int>>>>(size, v<v<v<int>>>(size, v<v<int>>(size, v<int>(size, inf))));
    DP dpwhite;
    DP dpblack;

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
                    dpblack.set(2+x1, 2+x2, k, l) = 0;
                } 
            }
            // бьется ферзем
            
            int t1, t2;
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1--;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t2++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t2--;
            }

            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1--;
                t2--;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1++;
                t2++;
            }

            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1--;
                t2++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                if (t1==l && t2==k)
                    continue;
                dpblack.set(t1, t2, k, l) = 0;
                t1++;
                t2--;
            }
        }
        
    }
    int k = 5;
    int l = 5;

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
            if (dpwhite.get(i,j,k,l) != inf)
                continue;
            dpwhite.set(i,j,k,l) = -1;
            for (int x1 = -1; x1 < 2; x1++)
            {
                for (int x2 = -1; x2 < 2; x2++)
                {
                    if (x1 != 0 || x2 != 0) 
                        dpwhite.set(i,j,k,l) = max(dpblack.get(i+x1, j+x2, k, l), dpwhite.set(i,j,k,l)) ;
                }
                
            }            
        }}}}


        // ходит белый ферзь
        for (int i = 0; i < size; i++)
        {for (int j = 0; j < size; j++)
        {for (int k = 0; k < size; k++)
        {for (int l = 0; l < size; l++){
            if (dpblack.get(i, j, k, l) != inf)
            {
                continue;
            }
            
            int t1, t2;
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t2++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1--;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t2--;
            }

            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1--;
                t2--;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1++;
                t2++;
            }

            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1--;
                t2++;
            }
            t1 = l;
            t2 = k;
            while (0 <= t1 && 0 <= t2 && t1 < size && t2 < size && !(t1 == 2 && t2 == 2)) {
                dpblack.set(i, j, k, l) = min(dpblack.get(i, j, k, l), 1 + dpwhite.get(i, j, t1, t2));
                t1++;
                t2--;
            }
            

        }}}}

        
    }
    

    int max_steps = -2;
    // int min_steps = inf;

    for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
    for (int k = 0; k < size; k++){
    for (int l = 0; l < size; l++){
        if (k == 2 && l == 2)
            continue;
        max_steps = max(max_steps, dpblack.get(i, j, k, l));                
        // min_steps = min(min_steps, dpblack.get(i, j, k, l));
        // cout << dpblack.get(i, j, k, l) << " ";
        // cout << dpwhite.get(i, j, k, l) << " ";
    }
    // cout << endl;
    }}}


    int i = 7;
    int j = 6;
    for (int k = 0; k < size; k++){
    for (int l = 0; l < size; l++){
        // cout << dpblack.get(i, j, k, l) << "\t";
        cout << dpwhite.get(i, j, k, l) << "\t";
    }
    cout << endl;
    }

    cout << endl;

    // for (int i = 0; i < size+1; i++){
    // for (int j = 0; j < size+1; j++){
    //     int k = 6;
    //     int l = 5;
    //     cout << dpblack.get(i, j, k, l) << " ";
    //     // cout << dpwhite.get(i, j, k, l) << " ";
    // }
    // cout << endl;
    // }

    cout << "Mat is after maximum " << max_steps << " steps\n";
    // cout << "Mat is after minimum " << min_steps << " steps\n";


    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dpwhite.get(x1-1, y1-1, x2-1, y2-1);
       
}