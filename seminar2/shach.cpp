#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    if ((a - c + b - d)%2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }

}