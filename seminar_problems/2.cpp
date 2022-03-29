#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::sort;

int main(){
    freopen("input.txt", "r", stdin);

    int n; 
    cin >> n;
    int *arr = new int[n];
    pair<int, int> *indA = new pair<int, int>[n]; // value, index

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
        indA[i] = {arr[i], i};
    }
    sort(indA, indA + n); 

    for (int i = 0; i < n/2; i++)
    {
        std::swap(arr[indA[i].second], arr[indA[n-1-i].second]);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    delete[] arr;
}