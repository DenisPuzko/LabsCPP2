#include <iostream>
using namespace std;

int main(void) {
    // Оголошення масиву за зразком [cite: 27]
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]); // [cite: 28]

    // --- Початок твого коду ---
    int *ptr = vector; // Вказівник на початок масиву 
    int min = *ptr;    // Припускаємо, що перший елемент найменший

    for (int i = 1; i < n; i++) {
        // Використовуємо арифметику вказівників замість індексації [cite: 23]
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }
    // --- Кінець твого коду ---

    cout << "Min element: " << min << endl;
    return 0; // [cite: 30]
}