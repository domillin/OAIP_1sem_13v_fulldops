#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** createSquareMatrix(int size) {
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 51 - 25; // Случайное число от -100 до 100
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int findSumOfPositiveRow(int** matrix, int size) {
    int totalSum = 0;
    bool foundPositiveRow = false;

    for (int i = 0; i < size; i++) {
        bool allPositive = true;
        int rowSum = 0;

        for (int j = 0; j < size; j++) {
            if (matrix[i][j] <= 0) {
                allPositive = false;
                break; // Если найден отрицательный элемент, выходим из цикла
            }
            rowSum += matrix[i][j];
        }

        if (allPositive) {
            foundPositiveRow = true;
            totalSum += rowSum; // Добавляем сумму положительной строки
        }
    }

    return foundPositiveRow ? totalSum : 0;
}

void reduceMatrixBySum(int** matrix, int size, int sum) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] -= sum; 
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    int size;
    cout << "Введите размер матрицы ";
    cin >> size;
    cout << endl;

   
    int** matrix = createSquareMatrix(size);

    
    cout << "Матрица:" << endl;
    printMatrix(matrix, size);

    
    int sum = findSumOfPositiveRow(matrix, size);

    if (sum > 0) {
        cout << "\nСумма положительных строк: " << sum << endl;

        // Уменьшаем матрицу на найденную сумму
        reduceMatrixBySum(matrix, size, sum);

        cout << "Матрица после уменьшения на сумму:" << endl;
        printMatrix(matrix, size);
    }
    else {
        cout << "\nВ матрице нет строк, все элементы которых положительны." << endl;
    }

    // Освобождаем память
    deleteMatrix(matrix, size);

    return 0;
}