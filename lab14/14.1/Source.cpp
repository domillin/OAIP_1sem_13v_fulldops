#include <iostream>
#include <cstdlib> // ��� srand � rand
#include <ctime>   // ��� time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, m = 0, n, x, max = 0, row2, col2;
    srand(static_cast<unsigned int>(time(0)));
    cout << "������� ���������� ����� � �������� ����������� ������� ";
    cin >> row;

    // ������� ������ ����������
    int** d2 = new int* [row];
    for (int i = 0; i < row; ++i) {
        d2[i] = new int[row]; // �������� ������ ��� ������� ����
    }

    //��������� ������ ���������� �������
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            d2[i][j] = rand() % 100;
        }
    }

    //����� ����������� �������
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < row; ++j) {
            cout << d2[i][j] << " ";
        }
        cout << endl;
    }
    max = 1000;
    cout << endl;
    for (int j = 0, i = 0; i < row; ++i, j++) {
        if (d2[i][j] <= max) {
            max = d2[i][j];
        }


    }
    cout << endl << "����������� ��������: " << max;
    for (int j = 0, i = 0; i < row; ++i, j++) {
        if (d2[i][j] == max) {
            row2 = i;
            break;
        }


    }
    cout << endl << "������� � ����������� ��������� ������� ���:" << endl;
    for (int j = 0; j < row; j++) {
        cout << d2[j][row2] << endl;
    }
}