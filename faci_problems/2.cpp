#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct something {
    int a;
    bool b;
    char c;
};

struct something* calc_address(struct something* start, unsigned int number) {
    return start + number;
}

void doubling(int** arr, unsigned int N) {
    int* a = new int[2*N];
    for (int i = 0; i < N; i++)
    {
        a[i] = (*arr)[i];
    }
    
    delete[] *arr;
    *arr = a;
}

#include <iostream>
void read_array(unsigned int** data, unsigned int* n, int gone) {
    unsigned t;
    if (std::cin >> t)
    {
        read_array(data, n, gone+1);
        (*data)[gone] = t;
    }
    else {
        *n = gone;
        *data = new unsigned int[*n];
    }
}

void read_array(unsigned int** data, unsigned int* n) {
    read_array(data, n, 0);
}

int** transpose(int const*const* matrix, unsigned int N, unsigned int M) {
    int** result = new int*[M];
    for (unsigned int i = 0; i < M; i++)
    {
        result[i] = new int[N];
        for (unsigned int j = 0; j < N; j++)
        {
            result[i][j] = matrix[j][i];
        }
        
    }
    return result;

}


int main()
{
    int* p = new int[3];
    p[0] = 10;
    p[1] = 10;
    p[2] = 10;
    
    delete[] p;
    int* d = new int[3];
    cout << d[0] << '\n';
    cout << d[1] << '\n';
    cout << d[2] << '\n';
    
    

    return 0;
}