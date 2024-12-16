#include <iostream>
#include <cstdlib> // Для malloc и free
#include <ctime>   // Для time()
#include <algorithm>
#include <Windows.h>
using namespace std;

int getCount(double* array, int size, int c,int countNum) {
    for (int i = 0; i < size; i++) {
        if (array[i] > c) {
            countNum++;
        }
    }
    return countNum;
}

double proizvedc(double* array, int size) {
    int product = 1;
    int max = 0;
    int control = 0;
    for (int i = 0; i < size; i++) {
        array[i] = abs(array[i]);
        if (array[i] > max) {
            max = array[i];
            control = i;
        }
    }
    if (control < size) {
        for (int i = control + 1; i < size; i++) {
            product *= array[i];
        }
        return product != 1 ? product : 0;
    }
    else {
        return product = 0;
    }
   
}
string up(string word, int cursor) {
    string result = word;
    transform(result.begin(), result.end(), result.begin(), tolower);
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
    int x;
    cin >> x;
    switch (x) {
    case(1): {
        int size, c,countNum=0;
        cout << "Введите размер массива: ";
        cin >> size;
        cin >> c;
        srand(static_cast<unsigned int>(time(nullptr)));
        double* array = (double*)calloc(size, sizeof(double));

        if (array == nullptr) {
            cerr << "Ошибка выделения памяти!" << endl;
            return 1;
        }
        for (int i = 0; i < size; ++i) {
            cout << "Введите элемент " << i + 1 << ": ";
            cin >> array[i];

        }
        cout << "Massive: " << endl;
        for (int i = 0; i < size; ++i) {
            cout << *(array + i) << " ";
        }
        cout << endl << "number of elements = " << getCount(array, size, c, countNum);
        cout << endl << "Произведение = "<< proizvedc(array, size);
        free(array);
        break;
    }
    case(2): {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string word;
        int cursor = 0;
        int index = 0;
        cout << "Введите строку: ";
        while (cin >> word) {
            cout << up(word, cursor) << " ";

            if (cin.get() == '\n') { break; }
            cursor++;
        }
    }
    }
}
//+
