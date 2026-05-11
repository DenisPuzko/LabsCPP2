#include <iostream>
using namespace std;

int main(void) {
    int a = 8, b = 0, c = 0;
    cin >> b;
    try {
        if (b == 0) {
            throw string("Your input is not valid, you can't divide by zero.");
        }
        c = a / b;
    } catch (string& e) {
        cout << e << endl;
    }
    cout << c << endl;
    return 0;
}