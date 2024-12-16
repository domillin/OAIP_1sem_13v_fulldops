#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 201 - 100; // ��������� ����� �� -100 �� 100
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool checkColumns(int** matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        bool hasPositive = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        if (!hasPositive) {
            return false; // ������ ������� ��� ������������� ���������
        }
    }
    return true; // ��� ������� �������� ������������� ��������
}

void replaceNegativesInFirstInvalidColumn(int** matrix, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        bool hasPositive = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        if (!hasPositive) {
            // �������� ������������� �������� �� �� ������
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] < 0) {
                    matrix[i][j] = -matrix[i][j]; // ������ �� ������
                }
            }
            break; // ��������� ����� ������ ������
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����
    int rows = 4, cols = 6; // ������� �������

    // ������� �������
    int** matrix = createMatrix(rows, cols);

    // ������� �������� �������
    cout << "�������� �������:" << endl;
    printMatrix(matrix, rows, cols);

    // ��������� ������� � ��������� ������, ���� ����������
    if (!checkColumns(matrix, rows, cols)) {
        replaceNegativesInFirstInvalidColumn(matrix, rows, cols);
        cout << "\n������� ����� ������ ������������� ���������:" << std::endl;
        printMatrix(matrix, rows, cols);
    }
    else {
    cout << "\n��� ������� �������� ���� �� ���� ������������� �������." << std::endl;
    }


    deleteMatrix(matrix, rows);

    return 0;
}