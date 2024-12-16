#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

static bool searchwords(string word) {
    size_t length = word.length();
    string end;
    string endcontrol = "а€";
    for (int i = length-1; i >=length-2; i--) {
        end += word[i];
    }
    reverse(end.begin(), end.end());
    if (end == endcontrol) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    int index = 0;
    cout << "¬ведите строку: ";
    while (cin >> word) {
        if (searchwords(word)) {
            cout << word;
        }
        
        if (cin.get() == '\n') { break; }

    }
    return 0;
}