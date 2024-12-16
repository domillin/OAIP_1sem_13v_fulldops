#include <iostream>
#include <fstream>
#include <cctype> 
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ofstream fileF1("F1.txt");
    if (!fileF1) {
        cerr << "Ошибка создания файла F1.txt!" << endl;
        return 1;
    }
    fileF1 << "123 Example 1" << endl;
    fileF1 << "Text" << endl;
    fileF1 << "456 LINE" << endl;
    fileF1 << "SYMBTEXTS" << endl;
    fileF1 << "789 FROMNUM" << endl;
    fileF1.close();

    ifstream inputFile("F1.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла F1.txt!" << endl;
        return 1;
    }

    ofstream outputFile("F2.txt");
    if (!outputFile) {
        cerr << "Ошибка создания файла F2.txt!" << endl;
        inputFile.close();
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (!line.empty() && isdigit(line[0])) { // Проверяем, начинается ли строка с цифры
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    cout << "Файл F2.txt успешно создан с нужными строками." << endl;
    return 0;
}
