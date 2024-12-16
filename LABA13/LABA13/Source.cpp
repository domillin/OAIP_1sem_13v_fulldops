#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    int index = 0,max;
    cout << "Введите строку: ";
    while (cin >> word) {
        index++;
        if (index % 2 != 0) { // Если индекс нечётный
            cout << word << " ";
        }
        if (cin.get() == '\n') { break; }
    }
    return 0;
}