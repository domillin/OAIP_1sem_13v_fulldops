#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // �������� ��������� ����� ��� ������
    ifstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        cerr << "������ �������� ����� fileF1.txt!" << endl;
        return 1;
    }

    // �������� ��������� ����� ��� ������
    ofstream outputFile("F2.txt");
    if (!outputFile.is_open()) {
        cerr << "������ �������� ����� fileF2.txt!" << endl;
        return 1;
    }

    int k;
    cout << "������� ����� ������ k (��������� � 1): ";
    cin >> k;

    if (k <= 0) {
        cerr << "�������� ����� ������!" << endl;
        return 1;
    }

    string line;
    int currentLine = 0;

    // ������ ����� �� ����� F1 � ������ ������ ����� � ���� F2
    while (getline(inputFile, line)) {
        currentLine++;
        if (currentLine >= k && currentLine <= k + 3) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "���� fileF2.txt ������� ������." << endl;
    return 0;
}
