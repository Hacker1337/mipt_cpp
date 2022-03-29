#include "functions.cpp"
#include <math.h>
#include <cmath>
#include <iomanip>

#include <iostream>
using namespace std;


float const f_pi = 3.14159265359f;
double const d_pi = 3.14159265359;
float const f_e = 2.718281828459f;
double const d_e = 2.718281828459;


float max_dist(float T, float v) {
    return exp(-v*v/T)/sqrt(T*M_PI);
}
float abs_v(float v) {
    return abs(v);
}
float true_mean(float T){
    return sqrt(T/M_PI);
}


int main(){
    cout << setprecision(10);
    const int size = 100000;
    float vmax = 10;
    float T = 1;

    float vel[size];
    float dens[size];
    float value[size];
    float dv = 2*vmax*(1.f)/size;

    for (int i = 0; i < size; i++)
    {
        vel[i] = -vmax +2*vmax*(i+0.f)/size;
        value[i] = abs_v(vel[i]);
        dens[i] = max_dist(T, vel[i]);
        // cout << vel[i] << endl;
    }
    float aim = true_mean(T);
    float res;
    
    res = mean(value, dens, dv, size);
    cout << "Naive summing example results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";

    res = kehen_mean(value, dens, dv, size);
    cout << "Kehen summing results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";

    res = doub_mean(value, dens, dv, size);
    cout << "Doubles summing results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";


    res = fma_mean(value, dens, dv, size);
    cout << "FMA summing results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";

    res = near_sum(value, dens, dv, size);
    cout << "Near summing results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";

    res = recursive_mean(value, dens, dv, size);
    cout << "Recursive summing results \n" 
    << res
    << "\ntrue value is\n" << aim << "\nrelative error is\n"
    << scientific << abs(res - aim)/aim
    << fixed << "\n\n";

    
    

    
    

    return 0;
}