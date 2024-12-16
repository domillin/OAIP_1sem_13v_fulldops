#include <windows.h>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string word, two;
    int index = 0, probel = 0, wordnum = 0, max;
    int k;
   
    cout << "Введите 1 строку: ";
    while (cin >> word) {
        if (cin.get() == '\n') { break; }
       
        if (index % 2 == 0) {
            size_t length = word.length();
            for (int i = word.length() - 1; i >= 0; --i) {
                two += word[i]; // Печатаем символы с конца
            }
            two += " ";
        }
     
    }
    cout << two;

    return 0;
}