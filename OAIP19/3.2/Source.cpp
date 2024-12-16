#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream fA("NameA.txt"), fB("NameB.txt"), fC("NameC.txt");
    ofstream fD("NameD.txt");

    if (!fA.is_open() || !fB.is_open() || !fC.is_open() || !fD.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }

    int a, b, c;

    // Чтение элементов из всех файлов и запись в новый файл
    while (fA >> a && fB >> b && fC >> c) {
        fD << a << " " << b << " " << c << " ";
    }

    cout << "Создание файла завершено." << endl;
    return 0;
}