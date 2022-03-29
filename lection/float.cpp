//https://github.com/MarkShevelev/LPHI_2022

#include <iomanip>
#include <iostream>

using namespace std;
void print_b(float f) {
    union fused_float_unsigned_t{
        float f;
        unsigned u;
    } fu;
    fu.f = 1.f;
    for (size_t i = 0; i < 32; i++)
    {
        cout << fu.u %2;
        fu.u >>=1;
    }
    cout << "\n";
    
}
void print_b(unsigned t) {
    
    for (size_t i = 0; i < 32; i++)
    {
        cout << t %2;
        t >>=1;
    }
    cout << "\n";
    
}
int main(){
    cout << setprecision(9) << fixed;
    union fused_float_unsigned_t{
        float f;
        unsigned u;
    } fu;
    fu.f = 2.f;
    // print_b(1u);
    cout << fu.f << " " << fu.u << "\n";

    fu.u+=1;
    cout << fu.f << " " << fu.u << "\n";
    // print_b(1000.f);
}