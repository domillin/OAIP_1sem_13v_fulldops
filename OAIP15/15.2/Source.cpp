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

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int num = 0;
    int control=0;
    for (int i = 0; i < rows; ++i) {
        num = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                num++;
           }
        }
        if (num == 0) {
            control = 1;
            break;
    }

    }
    if (control == 1) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                if (matrix[i][j] < 0) {
                    matrix[i][j] = 0;
                }
            }
            cout << endl;
        }
        cout << endl << "���������� �������: " << endl << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "������� �����������, ������ �� ��������.";
    }
   
}