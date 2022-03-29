#include "funcs.cpp"

using std::cin;
using std::cout;
using std::endl;
using namespace std;


int main(){
    cout << setprecision(16) << scientific;
    
    cout << "Test" << endl;
    cout << harm_sum(5'000'000) << '\n';
    cout << harm_sum_inv(5'000'000) << '\n';
    cout << harm_sum_d(5'000'000) << '\n';
    cout << kehen_sum(5'000'000) << '\n';
    cout << kehen_sum_d(5'000'000) << '\n';
    
}