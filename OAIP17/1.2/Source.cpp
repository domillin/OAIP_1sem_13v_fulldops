#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** createMatrix(int rows) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[i][j] = rand() % 15-1;
        }
    }
    return matrix;
}
int** createMatrix2(int rows) {
    int** matrix2 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix2[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrix2[i][j] = rand() % 15-1;
        }
    }
    return matrix2;
}
int** createMatrix3(int rows,int**matrix,int** matrix2) {
    int** matrix3 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix3[i] = new int[rows];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            matrix3[i][j] = matrix[i][j] * matrix2[i][j];
        }
    }
    return matrix3;
}
void printMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
bool hasAllPositiveElements(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < 0) {
                return false; 
            }
        }
    }
    return true; 
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "ru");
    int rows, min = 1000, numrow = 0;
    cin >> rows;
    cout << endl;
    int** matrix = createMatrix(rows);
    printMatrix(matrix, rows);
    cout << endl;
    int** matrix2 = createMatrix2(rows);
    printMatrix(matrix2, rows);
    cout << endl;
    if (hasAllPositiveElements(matrix, rows) && hasAllPositiveElements(matrix2, rows)) {
        int** matrix3 = createMatrix3(rows, matrix, matrix2);
        printMatrix(matrix3, rows);
        cout << endl;
        deleteMatrix(matrix3, rows);
    }
    else {
        cout << "negative";
    }
    deleteMatrix(matrix, rows);
    deleteMatrix(matrix2, rows);
    return 0;
}