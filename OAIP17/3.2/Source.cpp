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
            matrix[i][j] = rand() % 51 - 25; // ��������� ����� �� -100 �� 100
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
                break; // ���� ������ ������������� �������, ������� �� �����
            }
            rowSum += matrix[i][j];
        }

        if (allPositive) {
            foundPositiveRow = true;
            totalSum += rowSum; // ��������� ����� ������������� ������
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
    cout << "������� ������ ������� ";
    cin >> size;
    cout << endl;

   
    int** matrix = createSquareMatrix(size);

    
    cout << "�������:" << endl;
    printMatrix(matrix, size);

    
    int sum = findSumOfPositiveRow(matrix, size);

    if (sum > 0) {
        cout << "\n����� ������������� �����: " << sum << endl;

        // ��������� ������� �� ��������� �����
        reduceMatrixBySum(matrix, size, sum);

        cout << "������� ����� ���������� �� �����:" << endl;
        printMatrix(matrix, size);
    }
    else {
        cout << "\n� ������� ��� �����, ��� �������� ������� ������������." << endl;
    }

    // ����������� ������
    deleteMatrix(matrix, size);

    return 0;
}