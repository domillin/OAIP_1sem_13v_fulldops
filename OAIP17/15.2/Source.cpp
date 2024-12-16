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
            matrix[i][j] = rand() % 201 - 100; // Случайное число от -100 до 100
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
            return false; // Найден столбец без положительных элементов
        }
    }
    return true; // Все столбцы содержат положительные элементы
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
            // Заменяем отрицательные элементы на их модули
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] < 0) {
                    matrix[i][j] = -matrix[i][j]; // Замена на модуль
                }
            }
            break; // Завершаем после первой замены
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    int rows = 4, cols = 6; // Размеры матрицы

    // Создаем матрицу
    int** matrix = createMatrix(rows, cols);

    // Выводим исходную матрицу
    cout << "Исходная матрица:" << endl;
    printMatrix(matrix, rows, cols);

    // Проверяем столбцы и выполняем замену, если необходимо
    if (!checkColumns(matrix, rows, cols)) {
        replaceNegativesInFirstInvalidColumn(matrix, rows, cols);
        cout << "\nМатрица после замены отрицательных элементов:" << std::endl;
        printMatrix(matrix, rows, cols);
    }
    else {
    cout << "\nВсе столбцы содержат хотя бы один положительный элемент." << std::endl;
    }


    deleteMatrix(matrix, rows);

    return 0;
}