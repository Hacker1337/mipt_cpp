#include <iostream>
#include <algorithm>

using namespace std;

void corner(int** arr, int step, int size, int counter) {

}

int main(){
    // freopen("input.txt", "r", stdin);

    int n; 
    cin >> n;
    int **arr = new int*[n];

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    
    int counter = 0;
    for (int wall = 0; wall < (n+1)/2; ++wall)
    {
        for (int i = wall; i < n-wall; i++)
        {
            arr[i][wall] = counter++;
        }
        for (int j = wall+1; j < n-wall; j++)
        {
            arr[n-wall-1][j] = counter++;
        }
        for (int i = n-wall -1 - 1; i >= wall; i--)
        {
            arr[i][n-wall-1] = counter++;
        }
        for (int j = n - wall - 1 - 1; j >= wall + 1; j--)
        {
            arr[wall][j] = counter++;
        }
        
    }

    

    for (size_t i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
       
    
    for (size_t i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}