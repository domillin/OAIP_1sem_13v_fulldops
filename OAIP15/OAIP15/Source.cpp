#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size;
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

    }
    cout << "Massive: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << *(array + i) << " ";
    }
    double sum;
    sum = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            sum += *(array + i);
        }
    }
    cout << endl << "Summa = " << sum;
    int z = 0;
    int from=0, to=0;
    for (int i = 0; i < size; i++) {
        if (*(array + i) < 0) {
            from = i;
            break;
        }
    }
    for (int i = size-1; i > 0; i--) {
        if (*(array + i) < 0) {
            to = i;
            break;
        }
    }
    double sum2 = 0;
    for (int z = from + 1; z < to ; z++) {

        sum2 += *(array + z);

    }
    cout << endl << "from > to = " << sum2;
    free(array);
}
//+
