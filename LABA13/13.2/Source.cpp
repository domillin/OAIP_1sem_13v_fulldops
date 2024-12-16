#include <iostream>
#include <windows.h>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word;
    int index = 0,probel=0,wordnum=0;
    int k;
    int* ptr = &index;
    cout << "¬ведите k: ";
    cin >> k;
    cout << "¬ведите строку: ";
    while (cin >> word) {
        probel++;
        wordnum++;
        
        size_t length = word.length();
        size_t* ptr2 = &length;
        if (k >= *ptr && k <= *ptr + *ptr2+1) { cout << wordnum; break; }
        else {
            *ptr = *ptr + *ptr2 + 1;
        }
        if (cin.get() == '\n') { break; }
    }
    return 0;
}