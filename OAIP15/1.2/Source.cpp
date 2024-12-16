#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
    int rows, cols;
    cout << "������� ���������� �����: ";
    cin >> rows;
    cout << "������� ���������� ��������: ";
    cin >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "������� ������� " << i + 1 << " ������ " << j + 1 << " ����: ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    int positive = 0, control = 0;
    for (int j = 0;j < cols; ++j) {
        positive = 0;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] > 0) {
                positive++;
            }
            
            
        }
        if (positive == rows) {
            control = j;
            break;
        }
    }
    if (control == 0) {
        cout << "��� ������� �������, ��������� ����������� ����������";
    }
    else {
        control -= 1;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][control] > 0) {
                matrix[i][control] = matrix[i][control] - 2 * matrix[i][control];
            }
            else {
                matrix[i][control] = abs(matrix[i][control]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}