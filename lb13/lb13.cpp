#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int N;
    cout << "Enter the size of the square matrix (N): ";
    cin >> N;

    int **matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        *(matrix + i) = new int[N];
    }

    cout << "\nGenerated matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(*(matrix + i) + j) = rand() % 100;
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }

    cout << "\nMain diagonal: ";
    for (int i = 0; i < N; i++) {
        cout << *(*(matrix + i) + i) << " ";
    }

    cout << "\nSecondary diagonal: ";
    for (int i = 0; i < N; i++) {
        cout << *(*(matrix + i) + (N - 1 - i)) << " ";
    }

    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (*(*(matrix + i) + j) % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    cout << "\n\nEven numbers count: " << evenCount;
    cout << "\nOdd numbers count: " << oddCount << endl;

    for (int i = 0; i < N; i++) {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    return 0;
}