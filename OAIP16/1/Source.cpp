#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <algorithm>
#include<string>
#include <Windows.h>
using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    cout << "Матрица: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }
}
void steps(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i+=2) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = abs(matrix[i][j]);
            }
        }
        cout << endl;
    }
}
void input(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Введите элемент " << i + 1 << " строки " << j + 1 << " ряда: ";
            cin >> matrix[i][j];
        }
    }
}
string firstup(string words) {
    size_t length = words.length();
    if (length == 0) return words; 
    words[0] = toupper(words[0]);

    for (size_t i = 0; i < length - 1; i++) {
        if (words[i] == ' ' || words[i] == '.') {
            if (i + 1 < length) {
                words[i + 1] = toupper(words[i + 1]);
            }
        }
    }
    return words;
}



int main() {
    setlocale(LC_ALL, "ru");
    int x;
    cin >> x;
    switch (x) {
    case(1): {
        int rows, cols;
        cout << "Введите количество строк: ";
        cin >> rows;
        cout << "Введите количество столбцов: ";
        cin >> cols;

        int** matrix = (int**)malloc(rows * sizeof(int*));

       
        if (matrix == NULL) {
            std::cerr << "Ошибка выделения памяти!" << std::endl;
            return 1;
        }

      
        for (int i = 0; i < rows; ++i) {
            matrix[i] = (int*)malloc(cols * sizeof(int));

           
            if (matrix[i] == NULL) {
                std::cerr << "Ошибка выделения памяти!" << std::endl;
                
                for (int j = 0; j < i; ++j) {
                    free(matrix[j]);
                }
            }
        }
        input(matrix, rows, cols);

        printMatrix(matrix, rows, cols);

        steps(matrix, rows, cols);

        printMatrix(matrix, rows, cols);

        for (int i = 0; i < rows; ++i) {
            free(matrix[i]);
        }

        
        free(matrix);
        break;
    }
    case(2): {
        cin.ignore();
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string words;
        cout << "Введите строку: ";
        while (true) {
            getline(cin, words);
            words = firstup(words);
            cout << words << endl;
            return 0;
           
        }
        }
    }
    }
