#include <cmath>

float mean(float const psi[], float const pdf[], float const dv, unsigned size) 
{ 
    float sum = 0; 
    for (unsigned idx = 0; idx != size; ++idx) 
        sum += psi[idx] * pdf[idx]; 

    return dv * sum; 
}

float kehen_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    float sum = 0; 
    float t = 0;

    for (unsigned idx = 0; idx != size; ++idx) {
        float add = psi[idx] * pdf[idx]-t;
        float newsum = sum + add;
        t = newsum - sum - add;
        sum = newsum;
    }
    return dv * sum; 
}

double doub_mean(float const psi[], float const pdf[], float const dv, unsigned size) {
    double sum = 0;
    for (unsigned idx = 0; idx != size; ++idx) 
        sum += static_cast<double>(psi[idx]) * pdf[idx]; 

    return dv * sum;   
}

float fma_mean(float const psi[], float const pdf[], float const dv, unsigned size) 
{ 
    float sum = 0.f; 
    for (unsigned idx = 0; idx != size; ++idx) 
        sum = std::fma(psi[idx], pdf[idx], sum); 

    return dv * sum; 
}


float near_sum(float const psi[], float const pdf[], float const dv, unsigned size) 
{ 
    float* result = new float[size];
    for (unsigned idx = 0; idx != size; ++idx) 
        result[idx] = psi[idx] * pdf[idx]; 

    int step = 1;
    while (step < size)
    {
        int i = 0;
        while (i+step < size) {
            result[i] = result[i] + result[i+step];
            result[i + step] = 0;
            i += 2*step;
        }
        step <<= 1;        
    }

    float sum = result[0]; 
    delete[] result;
    return dv * sum; 
}

float __recursive_sum(float const psi[], float const pdf[], unsigned size) 
{
    if (size == 1)
    {
        return psi[0] * pdf[0];
    }
    return __recursive_sum(psi, pdf, size/2) + __recursive_sum(psi + size/2, pdf + size/2, size - size/2);
}

float recursive_mean(float const psi[], float const pdf[], float const dv, unsigned size) 
{
    return dv * __recursive_sum(psi, pdf, size); 
}