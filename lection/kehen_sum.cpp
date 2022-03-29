#include <iostream>
#include <iomanip>


using std::cin;
using std::cout;
using std::endl;
using namespace std;

float harm_sum(int n) {
    float sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum += 1.f/i;
    }
    return sum;
}
double harm_sum_d(int n) {
    double sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum += 1.0/i;
    }
    return sum;
}

float harm_sum_inv(int n) {
    float sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += 1.f/i;
    }
    return sum;
}

float kehen_sum(int n) {
    float sum = 0;
    float t = 0;
    for (size_t i = 1; i <= n; i++)
    {
        float add = 1.f/i-t;
        float result = sum + add;
        t = result - sum - add;
        sum = result;
    }
    return sum;
}

double kehen_sum_d(int n) {
    double sum = 0;
    double t = 0;
    for (size_t i = 1; i <= n; i++)
    {
        double add = 1.0/i-t;
        double result = sum + add;
        t = result - sum - add;
        sum = result;
    }
    return sum;
}



int main(){
    cout << setprecision(16) << scientific;
    
    cout << "Test" << endl;
    cout << harm_sum(5'000'000) << '\n';
    cout << harm_sum_inv(5'000'000) << '\n';
    cout << harm_sum_d(5'000'000) << '\n';
    cout << kehen_sum(5'000'000) << '\n';
    cout << kehen_sum_d(5'000'000) << '\n';
    
}