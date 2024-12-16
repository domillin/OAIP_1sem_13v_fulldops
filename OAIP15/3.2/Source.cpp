#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int rows = 4, cols = 4, summin = 0, summax = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i += 2) {
        int min = 1110;
        for (int j = 0; j < cols; ++j) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
        }
        summin += min;
    }
    cout << endl;
    cout << "Сумма наименьших элементов ее нечетных строк = " << summin << endl;
    for (int i = 1; i < rows; i += 2) {
        int max = 0;
        for (int j = 0; j < cols; ++j) {
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
        }
        summax += max;
    }
    cout << endl;
    cout << "Сумма наибольших элементов ее четных строк = " << summax << endl;
}