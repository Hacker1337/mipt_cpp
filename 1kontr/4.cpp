#include <iostream>
using std::cout;
using std::endl;

const unsigned int N = 5;
const int left[N]  = {5, 4, 3, 2, 1}; // command code 1
const int right[N] = {1, 2, 3, 4, 5}; // command code 2
const int back[N]  = {1, 1, 1, 1, 1}; // command code 3
const int meow[N]  = {3, 2, 3, 2, 5}; // command code 4


bool check_eq(int* begin, const int* str) {
    for (int i = 0; i < N; i++)
    {
        if (*(begin+i) != *(str+i)) {
            return false;
        }
    }
    return true;
    
}
void recognize(int* data_start, int* data_end, int* command, int** frame) {
    for(int* p = data_start; p + N <= data_end; p++) {
        if (check_eq(p, left))
        {
            *command = 1;
            *frame = p; 
            return;
        }
        if (check_eq(p, right))
        {
            *command = 2;
            *frame = p; 
            return;
        }
        if (check_eq(p, back))
        {
            *command = 3;
            *frame = p; 
            return;
        }
        if (check_eq(p, meow))
        {
            *command = 4;
            *frame = p; 
            return;
        } 
    }
    *command = 0;
}
// Здесь ваша реализация функции. Можете писать свои вспомогательные функции, только не забудьте их тоже отправить.

int main()
{
    const int L = 21;
    int mindstream[L] = {3, 2, 3, 2, 5, 2, 3, 8, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5};
    int command = -1;
    int* frame = mindstream;
    int* end = mindstream + L;
    while (command)
    {
        recognize(frame, end, &command, &frame);
        if (!command) break;
        switch(command)
        {
            case 1:
                cout << "left ";
                break;
            case 2:
                cout << "right ";
                break;
            case 3:
                cout << "back ";
                break;
            case 4:
                cout << "MEOOOOW ";
                break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}