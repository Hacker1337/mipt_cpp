#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    int n; 
    cin >> n;
    int** a = new int*[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        
    }

    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += a[i][n-1-i];
    }
    cout << sum;
    
    for (size_t i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    
    delete[] a;
    return 0;
}