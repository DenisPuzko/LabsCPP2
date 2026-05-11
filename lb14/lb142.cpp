#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int rows = 3;
    int cols = 3;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    int even_count = 0;
    int odd_count = 0;

    cout << "Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << "\t";
            
            if (arr[i][j] % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }
        cout << "\n";
    }

    cout << "Main diagonal elements: ";
    for (int i = 0; i < rows; i++) {
        cout << arr[i][i] << " ";
    }
    cout << "\n";

    cout << "Secondary diagonal elements: ";
    for (int i = 0; i < rows; i++) {
        cout << arr[i][cols - 1 - i] << " ";
    }
    cout << "\n";

    cout << "Even elements count: " << even_count << "\n";
    cout << "Odd elements count: " << odd_count << "\n";

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}