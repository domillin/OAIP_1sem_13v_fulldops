#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <algorithm>
#include <Windows.h>
#include <string>
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
    int sum=0;
    for (int i = 1; i < rows; i ++) {
        
        for (int k = 0; k < i; k++) {
            sum += matrix[i][k];
        }
    }
    cout << endl << sum;
}
void input(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 90;
        }
    }
}
int summa(const string& word, int num) {
    size_t length = word.length();
    for (size_t i = 0; i < length; i++) {
        if (word[i] == 'm') { 
            num++;
        }
    }
    return num; 
}



int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    setlocale(LC_ALL, "ru");
    int x;
    cin >> x;
    switch (x) {
    case(1): {
        int rows;
        cout << "Введите количество строк и столбцов: ";
        cin >> rows;


        int** matrix = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[rows]; 
        }
        input(matrix, rows, rows);

        printMatrix(matrix, rows, rows);

        steps(matrix, rows, rows);

        break;
    }
    case(2): {
        string word;
        int result = 0;

        while (true) {
            if (word == "exit") { break; }
            getline(cin, word); 
            int num = summa(word, 0); 
            result += num;          
        }

        cout << result;
    }
    }
}
//+
