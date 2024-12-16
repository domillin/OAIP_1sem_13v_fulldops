#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // �������� ��������� ����� ��� ������
    FILE* inputFile;
    if (fopen_s(&inputFile, "fA.txt", "r") != 0 || !inputFile) {
        cerr << "������ �������� ����� fA.txt!" << endl;
        return 1;
    }
    FILE* inputFile2;
    if (fopen_s(&inputFile2, "fB.txt", "r") != 0 || !inputFile2) {
        cerr << "������ �������� ����� fB.txt!" << endl;
        return 1;
    }
    int stolb;
    if (fscanf_s(inputFile, "%d", &stolb) != 1 || stolb <= 0) {
        cerr << "������ ������ ���������� �������� ��� �������� ��������!" << endl;
        fclose(inputFile);
        return 1;
    }
    int stolb2;
    if (fscanf_s(inputFile2, "%d", &stolb2) != 1 || stolb2 <= 0) {
        cerr << "������ ������ ���������� �������� ��� �������� ��������!" << endl;
        fclose(inputFile2);
        return 1;
    }
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
    double* matrix2 = nullptr;
    int capacity2 = 100, size2 = 0;
    double value2;
    double* temp2 = (double*)realloc(matrix2, capacity2 * sizeof(double));
    matrix2 = temp2;
    while (fscanf_s(inputFile2, "%lf", &value2) == 1) {


        if (!temp2) {
            cerr << "������ ��������� ������!" << endl;
            free(matrix2);
            fclose(inputFile2);
            return 1;
        }

        matrix2[size2++] = value2;
    }
    int stroka = size / stolb;
    int stroka2 = size2 / stolb2;

}
