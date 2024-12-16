#include <iostream>
#include <cstdarg>
#include <limits.h>

using namespace std;

void fmin(int count, ...) {
    va_list n;
    va_start(n, count);

    int min = INT_MAX; 

    for (int i = 0; i < count; i++) {
        int value = va_arg(n, int); 
        if (value < min) {
            min = value; 
        }
    }

    va_end(n); 
    cout << "����������� ��������: " << min << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "������ �����:" << endl;
    fmin(3, 10, 255, 1024);
    cout << "������ �����:" << endl;
    fmin(4, -10, 255, 1024,-3);
    cout << "������ �����:" << endl;
    fmin(2, 120, -255);
    return 0;
}
//�������, ��������� � ������������ ������ - ����������, ������������� va_list - ����� ����������� ������