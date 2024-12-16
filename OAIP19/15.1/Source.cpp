#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // �������� ��������� ����� ��� ������
    FILE* inputFile;
    if (fopen_s(&inputFile, "fileA.txt", "r") != 0 || !inputFile) {
        cerr << "������ �������� ����� fileA.txt!" << endl;
        return 1;
    }

    int columns;
    if (fscanf_s(inputFile, "%d", &columns) != 1 || columns <= 0) {
        cerr << "������ ������ ���������� �������� ��� �������� ��������!" << endl;
        fclose(inputFile);
        return 1;
    }

    // ������������ ��������� ������ ��� �������
    double* matrix = nullptr;
    int capacity = 100, size = 0;
    double value;
    double* temp = (double*)realloc(matrix, capacity * sizeof(double));
    matrix = temp;
    while (fscanf_s(inputFile, "%lf", &value) == 1) {


        if (!temp) {
            cerr << "������ ��������� ������!" << endl;
            free(matrix);
            fclose(inputFile);
            return 1;
        }

        matrix[size++] = value;
    }
    fclose(inputFile);

    // �������� �� ������������ ������
    if (size % columns != 0) {
        cerr << "������ ��������� ������� � �����!" << endl;
        free(matrix);
        return 1;
    }

    int rows = size / columns;
    int k;
    cout << "������� ����� ������� ��� ���������� (�� 1 �� " << columns << "): ";
    cin >> k;

    if (k < 1 || k > columns) {
        cerr << "�������� ����� �������!" << endl;
        free(matrix);
        return 1;
    }

    // �������� ��������� ����� ��� ������
    FILE* outputFile;
    if (fopen_s(&outputFile, "fileB.txt", "w") != 0 || !outputFile) {
        cerr << "������ �������� ����� fileB.txt!" << endl;
        free(matrix);
        return 1;
    }

    fprintf(outputFile, "%d\n", rows); // ���������� ���������� ��������� � �������
    for (int i = 0; i < rows; ++i) {
        fprintf(outputFile, "%.6lf\n", matrix[i * columns + (k - 1)]);
    }

    fclose(outputFile);
    free(matrix);

    cout << "���� fileB.txt ������� ������ � k-�� �������� �������." << endl;
    return 0;
}
