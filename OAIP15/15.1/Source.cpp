#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size, c, num = 0;
    cout << "������� ������ �������: ";
    cin >> size;
    cout << "������� c: ";
    cin >> c;
    srand(static_cast<unsigned int>(time(nullptr)));

    double* array = (double*)calloc(size, sizeof(double));

    if (array == nullptr) {
        cerr << "������ ��������� ������!" << endl;
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        cout << "������� ������� " << i + 1 << ": ";
        cin >> array[i];
        if (array[i] < c) {
            num++;
        }
    }
    cout << "Massive: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << *(array + i) << "  ";
    }
    cout << endl;
    int sum=0;
    for (int i = size-1; i >= 0; i--) {
        if (array[i] < 0) {
            break;
        }
        else {
            sum += array[i];
        }
    }
    cout << endl << "���������� ��������� ������� ����� �: " << num<<endl;
    cout <<"����� ��������� �������, ������������� ����� ���������� �������������� �����: "<< sum;
    cout << endl << endl;
}
