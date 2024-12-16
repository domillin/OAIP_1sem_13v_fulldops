#include <windows.h>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string word, two;
    int index = 0, probel = 0, wordnum = 0, max,num=0;
    int k;
    cout << "¬ведите окончание: ";
    cin >> two;
    cout << "¬ведите 1 строку: ";
    while (cin >> word) {
        index++;
        string s;
        int k = word.length();
        for (int i = word.length()-two.length(); i <= word.length() - 1; i++) {
            s += word[i];
        }
        if (s == two) { num++; }
        if (cin.get() == '\n') { break; }
    }
    cout << num;
    return 0;
}
