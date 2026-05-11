#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int n;
    cout << "Enter array size: ";
    cin >> n;

    float* arr = new float[n];
    int positive_count = 0;
    int negative_count = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = -2.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 4.0f));

        if (arr[i] > 0) {
            positive_count++;
        } else if (arr[i] < 0) {
            negative_count++;
        }
    }

    cout << "Array elements: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nPositive numbers count: " << positive_count << "\n";
    cout << "Negative numbers count: " << negative_count << "\n";

    delete[] arr;
    return 0;
}