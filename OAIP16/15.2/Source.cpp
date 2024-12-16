#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

string up(string word,int cursor) {
    string result = word;
    if (cursor == 0) {
        transform(result.begin(), result.end(), result.begin(), toupper);
        return result;
    }
    else {
        return result;
    }
    
}


int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    int cursor = 0;
    int index = 0;
    cout << "¬ведите строку: ";
    while (cin >> word) {
        cout<<up(word, cursor)<<" ";

        if (cin.get() == '\n') { break; }
        cursor++;
    }
    return 0;
}