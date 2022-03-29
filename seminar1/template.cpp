#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);

    int n; 
    cin >> n;
    int *arr = new int[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
 

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
       
}