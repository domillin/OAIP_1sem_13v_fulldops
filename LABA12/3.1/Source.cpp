#include <iostream> 
#include <cstdlib> // ƒл€ функции rand() и srand() 
#include <ctime>   // ƒл€ функции time() 
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size, t, count = 0, counttwo = 0; // ѕеременна€ дл€ хранени€ размера массива 

    cout << "¬ведите размер массива: ";
    cin >> size;
    cin >> t;
    // ƒинамическое выделение пам€ти под массив 
    int* array = new int[size];
    int* B = new int[size];
    // »нициализаци€ генератора случайных чисел 
    srand(time(NULL));

    // «аполнение массива случайными числами 
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 30;
    }
    for (int i = 0; i < size; i++) {
        *(B + i) = rand() % 30;
    }
    for (int i = 0; i < size; i++) {
        if (*(array + i) < t) {
            count++;
        }
    }
    for (int i = 0; i < size; i++) {
        if (*(B + i) < t) {
            counttwo++;
        }
    }
    cout << "колличесвто элементов в массиве ј меньших t " << count;
    cout << endl;
    cout << "колличесвто элементов в массиве B меньших t " << counttwo;
    cout << endl;

    if (count > counttwo) {
        cout << "Ёлементы массива A: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
        cout << "Ёлементы массива B: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(B + i) << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ёлементы массива B: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(B + i) << " ";
        }
        cout << endl;
        cout << "Ёлементы массива A: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
    }


    delete[] array; 
    delete[] B;
}