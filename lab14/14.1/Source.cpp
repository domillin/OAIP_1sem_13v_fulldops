#include <iostream>
#include <cstdlib> // Для srand и rand
#include <ctime>   // Для time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, m = 0, n, x, max = 0, row2, col2;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Введите количество строк и столбцов двухмерного массива ";
    cin >> row;

    // создаем массив указателей
    int** d2 = new int* [row];
    for (int i = 0; i < row; ++i) {
        d2[i] = new int[row]; // выделяем память для каждого ряда
    }

    //заполняем массив случайными числами
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            d2[i][j] = rand() % 100;
        }
    }

    //вывод двухмерного массива
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << d2[i][j] << " ";
        }
        cout << endl;
    }
    max = 1000;
    cout << endl;
    for (int j = 0, i = 0; i < row; ++i, j++) {
        if (d2[i][j] <= max) {
            max = d2[i][j];
        }


    }
    cout << endl << "Минимальное значение: " << max;
    for (int j = 0, i = 0; i < row; ++i, j++) {
        if (d2[i][j] == max) {
            row2 = i;
            break;
        }


    }
    cout << endl << "Столбец с минимальным значением главной оси:" << endl;
    for (int j = 0; j < row; j++) {
        cout << d2[j][row2] << endl;
    }
}