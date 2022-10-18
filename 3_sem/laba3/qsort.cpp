#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

#include <vector>
using std::vector;

using std::swap;

template <typename T>
struct Comparator {
    virtual bool operator()(T const &, T const &) const = 0;
};
struct IntComparator final : Comparator<int> {
    bool operator()(int const &lha, int const &rha) const override {
        return lha < rha;
    }
};

template <typename T>
void my_qsort(T *beg, T *end, Comparator<T> &cmp) {
    if (end - beg <= 1) {
        return;
    }
    int pivot_i = rand() % (end - beg);
    T pivot = beg[pivot_i];
    int i = 0;
    int j = end - beg - 1;

    while (i <= j) {
        while (i < j && beg[i] < pivot) {
            i++;
        }
        while (i < j && beg[j] > pivot) {
            j--;
        }
        if (j <= i) {
            break;
        }
        swap(beg[i++], beg[j--]);
    }
    for (auto ptr = beg; ptr < end; ptr++)
    {
        cerr << *ptr << " ";
    }
    cerr << endl;
    cerr << "i = " << i << ". j = " << j << endl; 

    my_qsort(beg, beg + j, cmp);
    my_qsort(beg + j + 1, end, cmp);
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // изменить стандартный поток ввода
    // вывода
    int N = 30;
    int *massive = new int[N];
    for (int i = 0; i < N; i++) {
        massive[i] = 20 - i;
        cout << massive[i] << " ";
    }
    cout << endl;

    IntComparator cmp;
    my_qsort(massive, massive + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    {
        int N = 30;
        int *massive = new int[N];
        for (int i = 0; i < N; i++) {
            massive[i] = (8 * i) % 15;
            cout << massive[i] << " ";
        }
        cout << endl;

        IntComparator cmp;
        my_qsort(massive, massive + N, cmp);

        for (int i = 0; i < N; i++) {
            cout << massive[i] << " ";
        }
        cout << endl;


        delete[] massive;
    }
    
    for (int i = 0; i < N; i++) {
        massive[i] = (5 * i) % 7;
        cout << massive[i] << " ";
    }
    cout << endl;

    my_qsort(massive, massive + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        massive[i] = (11 * i) % 63;
        cout << massive[i] << " ";
    }
    cout << endl;

    my_qsort(massive, massive + N, cmp);

    for (int i = 0; i < N; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    delete[] massive;
}
