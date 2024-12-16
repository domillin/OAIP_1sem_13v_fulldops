#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream fA("NameA.txt"), fB("NameB.txt"), fC("NameC.txt");
    ofstream fD("NameD.txt");

    if (!fA.is_open() || !fB.is_open() || !fC.is_open() || !fD.is_open()) {
        cerr << "������ �������� �����" << endl;
        return 1;
    }

    int a, b, c;

    // ������ ��������� �� ���� ������ � ������ � ����� ����
    while (fA >> a && fB >> b && fC >> c) {
        fD << a << " " << b << " " << c << " ";
    }

    cout << "�������� ����� ���������." << endl;
    return 0;
}