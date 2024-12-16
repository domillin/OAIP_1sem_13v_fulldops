#include <iostream> 
#include <cstdlib> // ��� ������� rand() � srand() 
#include <ctime>   // ��� ������� time() 
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size, t, count = 0, counttwo = 0; // ���������� ��� �������� ������� ������� 

    cout << "������� ������ �������: ";
    cin >> size;
    cin >> t;
    // ������������ ��������� ������ ��� ������ 
    int* array = new int[size];
    int* B = new int[size];
    // ������������� ���������� ��������� ����� 
    srand(time(NULL));

    // ���������� ������� ���������� ������� 
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
    cout << "����������� ��������� � ������� � ������� t " << count;
    cout << endl;
    cout << "����������� ��������� � ������� B ������� t " << counttwo;
    cout << endl;

    if (count > counttwo) {
        cout << "�������� ������� A: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
        cout << "�������� ������� B: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(B + i) << " ";
        }
        cout << endl;
    }
    else {
        cout << "�������� ������� B: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(B + i) << " ";
        }
        cout << endl;
        cout << "�������� ������� A: " << endl;
        for (int i = 0; i < size; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
    }


    delete[] array; 
    delete[] B;
}