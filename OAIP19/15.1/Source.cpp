#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Открытие исходного файла для чтения
    FILE* inputFile;
    if (fopen_s(&inputFile, "fileA.txt", "r") != 0 || !inputFile) {
        cerr << "Ошибка открытия файла fileA.txt!" << endl;
        return 1;
    }

    int columns;
    if (fscanf_s(inputFile, "%d", &columns) != 1 || columns <= 0) {
        cerr << "Ошибка чтения количества столбцов или неверное значение!" << endl;
        fclose(inputFile);
        return 1;
    }

    // Динамическое выделение памяти для матрицы
    double* matrix = nullptr;
    int capacity = 100, size = 0;
    double value;
    double* temp = (double*)realloc(matrix, capacity * sizeof(double));
    matrix = temp;
    while (fscanf_s(inputFile, "%lf", &value) == 1) {


        if (!temp) {
            cerr << "Ошибка выделения памяти!" << endl;
            free(matrix);
            fclose(inputFile);
            return 1;
        }

        matrix[size++] = value;
    }
    fclose(inputFile);

    // Проверка на корректность данных
    if (size % columns != 0) {
        cerr << "Ошибка структуры матрицы в файле!" << endl;
        free(matrix);
        return 1;
    }

    int rows = size / columns;
    int k;
    cout << "Введите номер столбца для извлечения (от 1 до " << columns << "): ";
    cin >> k;

    if (k < 1 || k > columns) {
        cerr << "Неверный номер столбца!" << endl;
        free(matrix);
        return 1;
    }

    // Открытие выходного файла для записи
    FILE* outputFile;
    if (fopen_s(&outputFile, "fileB.txt", "w") != 0 || !outputFile) {
        cerr << "Ошибка открытия файла fileB.txt!" << endl;
        free(matrix);
        return 1;
    }

    fprintf(outputFile, "%d\n", rows); // Записываем количество элементов в столбце
    for (int i = 0; i < rows; ++i) {
        fprintf(outputFile, "%.6lf\n", matrix[i * columns + (k - 1)]);
    }

    fclose(outputFile);
    free(matrix);

    cout << "Файл fileB.txt успешно создан с k-ым столбцом матрицы." << endl;
    return 0;
}
