#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Открытие исходного файла для чтения
    ifstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла fileF1.txt!" << endl;
        return 1;
    }

    // Открытие выходного файла для записи
    ofstream outputFile("F2.txt");
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла fileF2.txt!" << endl;
        return 1;
    }

    int k;
    cout << "Введите номер строки k (нумерация с 1): ";
    cin >> k;

    if (k <= 0) {
        cerr << "Неверный номер строки!" << endl;
        return 1;
    }

    string line;
    int currentLine = 0;

    // Чтение строк из файла F1 и запись нужных строк в файл F2
    while (getline(inputFile, line)) {
        currentLine++;
        if (currentLine >= k && currentLine <= k + 3) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Файл fileF2.txt успешно создан." << endl;
    return 0;
}
