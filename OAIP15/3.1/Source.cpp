#include <iostream>
#include <cstdlib> // ��� malloc � free
#include <ctime>   // ��� time()
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size;
    cout << "������� ������ �������: ";
    cin >> size;
    srand(static_cast<unsigned int>(time(nullptr)));
   
    double* array = (double*)calloc(size, sizeof(double));

    if (array == nullptr) {
        cerr << "������ ��������� ������!" << endl;
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        cout << "������� ������� " << i + 1 << ": ";
        cin >> array[i];

    }
    cout << "Massive: " << endl;
    double max = 0;
    for (int i = 0; i < size; ++i) {
        cout << *(array + i) << "  ";
        if (max < array[i]) {
            max = array[i];
        }
    }
    int num = 0;
    for (int i = 0; i < size; ++i) {
        if (max == array[i]) {
            num = i;
        }
    }
    double um = 1, summ = 0;
    for (int i = 0; i < num; i++) {
        if (array[i]>0) {
            summ += array[i];
        }
        if (array[i] < 0) {
            um *= array[i];
        }
    }
    cout << endl << "Summa = " << summ << endl;
    cout << "Um = " << um;

    
   
}