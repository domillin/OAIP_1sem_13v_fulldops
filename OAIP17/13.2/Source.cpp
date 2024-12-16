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
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}
void searchMin(int min, int rows, int cols, int** matrix,int numrow ) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    for (int i = 0; i < rows; i++) {
       if (matrix[i][i]== min) {
           numrow = i + 1;
       
       }
    }
    if (numrow == 0) {
        cout << "mo min el";
    }
    else {
        cout << "minrow=" << numrow;
    }

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
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    setlocale(LC_ALL,"ru");
    int rows,min=1000,numrow=0;
    cin >> rows;
    cout << endl;
    int** matrix = createMatrix(rows, rows);
    printMatrix(matrix, rows, rows);
    cout << endl;
    searchMin(min, rows, rows, matrix, numrow);
    deleteMatrix(matrix, rows);
    return 0;
}