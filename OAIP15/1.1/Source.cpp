#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size, negative = 0;
    cout << "Введите размер массива: ";
    cin >> size;
    srand(static_cast<unsigned int>(time(nullptr)));
   
    double* array = (double*)calloc(size, sizeof(double));

    if (array == nullptr) {
        cerr << "Ошибка выделения памяти!" << endl;
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> array[i];
        if (array[i] < 0) {
            negative++;
        }
    }
    cout << "Massive: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << *(array + i) << "  ";
    }
    cout << endl << "Negative elemets = " << negative;

    for (int i = 0; i < size; ++i) {
        *(array + i) = abs(*(array + i));
    }
    double minimal = 100;
    for (int i = 0; i < size; ++i) {
        if (minimal > array[i]) {
            minimal = array[i];
        }
    }

    int number = 0;
    for (int i = 0; i < size; ++i) {
        if (minimal == array[i]) {
            number = i;
        }
    }
    double sum = 0;
    for (int i = number + 1; i < size; i++) {
        sum += array[i];
    }
    cout << endl << "Summa = " << sum;
}