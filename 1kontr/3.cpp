#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int* compress(int** matrix, int n, int m){

    bool ok = true;
    int* res = new int[3*n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] !=0)
            {
                if (k >= 3)
                {
                    ok = false;
                    break;
                }   
                res[i*3+k] = matrix[i][j];
                k++;
            }   
        }
        k = 0;
        if (!ok)
        {
            break;
        }
    }
    if (!ok) {
        delete[] res;
        res = nullptr;
    }
    // удаление матрицы
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return res;

}
// Здесь ваша реализация функции. 

int main()
{
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int* compressed = compress(a, n, m);

    // if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}