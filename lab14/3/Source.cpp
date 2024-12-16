
#include <iostream>
#include <cstdlib> // Для srand и rand
#include <ctime>   // Для time
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int row, col, x, max, m = 0;;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Введите количество строк и столбцов двухмерного массива ";
    cin >> row;
    cout << endl;
    int** d2 = new int* [row];
    for (int i = 0; i < row; ++i) {
        d2[i] = new int[row]; // выделяем память для каждого ряда
    }
    int** d22 = new int* [row];
    for (int i = 0; i < row; ++i) {
        d22[i] = new int[row]; // выделяем память для каждого ряда
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            d2[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << d2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int k = 0, n = 0;
    while (n < row) {
        int rowmax = 0, colmax = 0, max = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < row; ++j) {
                if (max < d2[i][j]) {
                    max = d2[i][j];
                    rowmax = i;
                    colmax = j;
                }
            }
        }
        swap(d2[n][n], d2[rowmax][colmax]);
        int rowss = n;
        while(rowss<row) {
            for (int j = 0; j < row; ++j) {
                d22[rowss][j] = d2[rowss][j];
            }
            rowss++;
        }
        d2[n][n] = 0;
        n++;
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << d22[i][j] << " ";
        }
        cout << endl;
    }
}