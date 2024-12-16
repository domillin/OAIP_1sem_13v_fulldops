
#include <iostream>
#include <cstdlib> // Для srand и rand
#include <ctime>   // Для time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, n=1, x, max, m = 0;;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Введите количество строк и столбцов двухмерного массива ";
    cin >> row;

    
    cout << endl;
   
    int* d1 = new int[row * row];
    int* d11 = new int[row * row];
    // создаем массив указателей
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
    
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < row; k++) {
            d1[m] = d2[i][k];
            m++;
        }
    }
    m = 0;
    for (int i = 0; i < row; i++) {
        for (int k = 0; k < row; k++) {
            d11[m] = d2[i][k];
            m++;
        }
    }
  
    int c=0,buf;
    n = 0;
    
    while (n <row) {
        max = 0;
        
        for (int k = 0; k < row * row; k++) {
            if (max < d1[k]) {
                max = d1[k];
            }
        }

        for (int k = 0; k < row * row; k++) {
            if (max == d1[k]) {
                buf = d11[c];
                d11[c] = max;
                d11[k] = buf;
                d1[k] = 0;
            }
        }
        c += row+1;
        n++;
    }
    
    m = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            d22[i][j] = d11[m];
            m++;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << d22[i][j] << " ";

        }
        cout << endl;
    }
}