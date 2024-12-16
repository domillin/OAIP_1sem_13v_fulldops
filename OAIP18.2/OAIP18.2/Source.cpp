#include <iostream>
#include <vector>
using namespace std;

int sumBelowMainDiagonal() {
    return 0;
}

template<typename... Matrices>
int sumBelowMainDiagonal(const vector<vector<int>>& matrix, Matrices... rest) {
    int sum = 0;
    int size = matrix.size();

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += matrix[i][j];
        }
    }

    return sum + sumBelowMainDiagonal(rest...);
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {3, 8, 1},
        {2, 4, 7},
        {9, 6, 5}
    };

    vector<vector<int>> matrix3 = {
        {2, 5, 8},
        {7, 1, 3},
        {4, 6, 9}
    };


    cout << "Сумма для одной матрицы (matrix1): " << sumBelowMainDiagonal(matrix1) << endl;   
    cout << "Сумма для двух матриц (matrix1 и matrix2): " << sumBelowMainDiagonal(matrix1, matrix2) << endl;  
    cout << "Сумма для трех матриц (matrix1, matrix2 и matrix3): " << sumBelowMainDiagonal(matrix1, matrix2, matrix3) << endl;

    return 0;
}
