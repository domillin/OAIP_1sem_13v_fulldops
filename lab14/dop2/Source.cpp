#include <iostream>
#include <cstdlib> // Для srand и rand
#include <ctime>   // Для time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, n, x, max = 0, row2, col2;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Введите количество строк и столбцов двухмерного массива ";
    cin >> row;

    // создаем массив указателей
    int** d2 = new int* [2 * row];
    for (int i = 0; i < 2 * row; ++i) {
        d2[i] = new int[2 * row];
    }
    int** d21 = new int* [2*row];
    for (int i = 0; i < 2*row; ++i) {
        d21[i] = new int[2*row];
    }

   
    for (int i = 0; i < 2 * row; ++i) {
        for (int j = 0; j < 2 * row; ++j) {
            d2[i][j] = rand() % 100;
        }
    }
    cout << "Изначальная матрица" << endl;
    for (int i = 0; i < 2 * row; ++i) {
        for (int j = 0; j < 2 * row; ++j) {
            cout << d2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << endl;
    int m = 0;
    int k = 0;
    for (int i = row; i < 2*row; i++) {
        m = 0;
        for (int j = row; j <2* row; j++) {
            
            d21[k][m] = d2[i][j];
            m++;
            
        }
        k++;
    }
    k = row;
    m = 0;
    for (int i = 0; i < row; ++i) {
        m = 0;
        for (int j = row; j < 2*row; ++j) {
            d21[k][m] = d2[i][j];
            m++;
        }
        k++;
    }
    k = 0;
    m = row;
    for (int i = row; i < 2 * row; ++i) {
        m = row;
        for (int j = 0; j < row; ++j) {

            d21[k][m] = d2[i][j];
            m++;
        }
        k++;
    }
    k = row;
    m = row;
    for (int i = 0; i <  row; ++i) {
        m = row;
        for (int j = 0; j < row; ++j) {

            d21[k][m] = d2[i][j];
            m++;
        }
        k++;
    }
    for (int i = 0; i < 2 * row; ++i) {
        for (int j = 0; j < 2 * row; ++j) {
            cout << d21[i][j] << " ";
        }
        cout << endl;
    }




}