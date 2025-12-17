#include <iostream>
using namespace std;

// ====================== Функції для введення та виведення ======================

// Функція для введення масиву
void inputArray(int arr[], int &n) {
    cout << "Введіть розмір масиву (N від 2 до 50): ";
    cin >> n;
    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Функція для виведення масиву
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ====================== Завдання 1: Знайти два однакові елементи ======================
void task1() {
    int arr[50], n;
    inputArray(arr, n);

    cout << "Початковий масив: ";
    printArray(arr, n);

    // Знаходимо два однакові елементи
    int index1 = -1, index2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                index1 = i + 1; // додаємо 1, бо нумерація з 1
                index2 = j + 1;
                break;
            }
        }
        if (index1 != -1) break;
    }

    cout << "Номери однакових елементів у порядку зростання: "
         << index1 << " " << index2 << endl;
}

// ====================== Завдання 2: Видалити всі повтори, залишивши останнє входження ======================
void task2() {
    int arr[50], n;
    inputArray(arr, n);

    cout << "Початковий масив: ";
    printArray(arr, n);

    // Видалення всіх повторюваних елементів, залишаючи останні входження
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                // Зсув елементів вліво
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; // зменшуємо розмір масиву
            } else {
                j++;
            }
        }
    }

    cout << "Масив після видалення повторів: ";
    printArray(arr, n);
}

// ====================== Функція main з меню ======================
int main() {
    int choice;

    do {
        cout << "\n======= МЕНЮ =======\n";
        cout << "1 - Завдання 1 (знайти два однакові елементи)\n";
        cout << "2 - Завдання 2 (видалити всі повтори, залишивши останні входження)\n";
        cout << "0 - Вихід\n";
        cout << "Виберіть пункт: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Вихід з програми.\n";
                break;
            default:
                cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}