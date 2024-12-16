#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>
using namespace std;

static bool searchwords(string word) {
    size_t length = word.length();
    string end;
    string endcontrol = "ая";
    for (int i = length - 1; i >= length - 2; i--) {
        end += word[i];
    }
    reverse(end.begin(), end.end());
    if (end == endcontrol) {
        return true;
    }
    else {
        return false;
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << "Матрица: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool searchA(int** matrix, int rows, int cols, int a, int& row_a, int* row_a_massive) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == a) {
                row_a = i;
                for (int k = 0; k < cols; k++) {
                    row_a_massive[k] = matrix[row_a][k];
                }
                return true; 
            }
        }
    }
    return false; 
}

bool searchB(int** matrix, int rows, int cols, int b, int& row_b, int* row_b_massive) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == b) {
                row_b = i;
                for (int k = 0; k < cols; k++) {
                    row_b_massive[k] = matrix[row_b][k];
                }
                return true; 
            }
        }
    }
    return false; 
}

void trade(int** matrix, int rows, int cols, int row_a, int row_b, int* row_b_massive, int* row_a_massive) {
    for (int i = 0; i < cols; i++) {
        swap(matrix[row_a][i], matrix[row_b][i]); 
    }
}

void input(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Введите элемент " << i + 1 << " строки " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int x;
    
    cin >> x;

    switch (x) {
    case 1: {
        int rows, cols, a, b, row_a = -1, row_b = -1;
        cout << "Введите количество строк: ";
        cin >> rows;
        cout << "Введите количество столбцов: ";
        cin >> cols;
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите b: ";
        cin >> b;

        int* row_a_massive = (int*)malloc(cols * sizeof(int));
        int* row_b_massive = (int*)malloc(cols * sizeof(int));


        if (row_a_massive == NULL || row_b_massive == NULL) {
            std::cerr << "Ошибка выделения памяти!" << std::endl;
            return 1;
        }

        int** matrix = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; ++i) {
            matrix[i] = (int*)malloc(cols * sizeof(int));
            if (matrix[i] == NULL) {
                std::cerr << "Ошибка выделения памяти!" << std::endl;
                return 1;
            }
        }

        input(matrix, rows, cols);

        printMatrix(matrix, rows, cols);

        if (searchA(matrix, rows, cols, a, row_a, row_a_massive) && searchB(matrix, rows, cols, b, row_b, row_b_massive)) {
            trade(matrix, rows, cols, row_a, row_b, row_b_massive, row_a_massive);
            printMatrix(matrix, rows, cols);
        }
        else {
            cout << "Не удалось найти один из элементов." << endl;
        }


        for (int i = 0; i < rows; ++i) {
            free(matrix[i]);
        }
        free(matrix);

        free(row_a_massive);
        free(row_b_massive);


        break;
    }
    case 2: {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string word;
        int index = 0;
        cout << "Введите строку: ";
        while (cin >> word) {
            if (searchwords(word)) {
                cout << word;
            }

            if (cin.get() == '\n') { break; }

        }
        return 0;
        break;
    }


          return 0;
    }
}