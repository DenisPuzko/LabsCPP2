#include <iostream>

using namespace std;

void increment(int& value) {
    value += 1;
}

void increment(int& value, int step) {
    value += step;
}

int main(void) {
    int var = 0;
    for(int i = 0; i < 10; i++)
        if(i % 2)
            increment(var);
        else
            increment(var, i);
    cout << var << endl;
    return 0;
}