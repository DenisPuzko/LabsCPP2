#include <iostream>
using namespace std;

int main(void) {
    int matrix[10][10] = { }; // Матриця, заповнена нулями [cite: 41]

    // --- Початок твого коду ---
    // Отримуємо вказівник на перший елемент [cite: 33]
    int *p = (int *)matrix; 

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Формула i * 10 + j дозволяє знайти потрібний елемент у "пласкій" пам'яті
            // (i+1)*(j+1) заповнює таблицю множення від 1 до 100 [cite: 35]
            *(p + (i * 10 + j)) = (i + 1) * (j + 1);
        }
    }
    // --- Кінець твого коду ---

    // Виведення за зразком [cite: 43-49]
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}