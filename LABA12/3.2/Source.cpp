#include <iostream> 
#include <cstdlib> 
#include <ctime>   
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size, t, count = 0, counttwo = 0, countthree = 0;

    cout << "������� ������ �������: ";
    cin >> size;

    // ������������ ��������� ������ ��� ������ 
    int* C = new int[size];
    int* B = new int[size];
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        *(C + i) = rand() % 30;
    }
    for (int i = 0; i < size; i++) {
        *(B + i) = rand() % 30;
    }

    cout << "�������� ������� C: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(C + i) << " ";
    }
    cout << endl;
    cout << "�������� ������� B: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(B + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        if (*(C + i) < *(B + i)) {
            count++;
        }
    }
    cout << "����������� ������� �[k]<B[k]= " << count << endl;
    for (int i = 0; i < size; i++) {
        if (*(C + i) > *(B + i)) {
            counttwo++;
        }
    }
    cout << "����������� ������� �[k]>B[k]= " << counttwo << endl;
    for (int i = 0; i < size; i++) {
        if (*(C + i) == *(B + i)) {
            countthree++;
        }
    }
    cout << "����������� ������� �[k]=B[k]= " << countthree;

    delete[] C; 
    delete[] B;
}