#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using namespace std;
// рассчет гармонического ряда

int main(){
    cout << setprecision(10);

    int max_number = 1000000000;
    float beginning_sum = 0;
    float end_sum = 0;

    for (int i = 0; i < max_number; i++)
    {
        beginning_sum += 1.0/(i+1);
        end_sum += 1./(max_number - i);
    }
    cout << "Max number is " << max_number << endl;
    cout << "Beginning sum " << beginning_sum << endl;
    cout << "End sum " << end_sum << endl;
    
}