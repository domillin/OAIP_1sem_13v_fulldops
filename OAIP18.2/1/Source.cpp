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
    cout << "Минимальное значение: " << min << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Первый вызов:" << endl;
    fmin(3, 10, 255, 1024);
    cout << "Второй вызов:" << endl;
    fmin(4, -10, 255, 1024,-3);
    cout << "Третий вызов:" << endl;
    fmin(2, 120, -255);
    return 0;
}
//примеры, указанные в лабораторной работе - некорректы, использование va_list - более современный подход