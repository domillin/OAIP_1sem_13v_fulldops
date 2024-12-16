#include <iostream>
#include <cstdarg>
#include <limits>

using namespace std;

double fmax(char type, int count, ...) {
    va_list args;
    va_start(args, count);

    if (type == 'i') { 
        int minInt = INT_MAX;

        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            if (value < minInt) {
                minInt = value; 
            }
        }

        va_end(args);
        return minInt; 
    }
    else if (type == 'd') { 
        double minDouble = INT_MAX;

        for (int i = 0; i < count; i++) {
            double value = va_arg(args, double);
            if (value < minDouble) {
                minDouble = value; 
            }
        }

        va_end(args);
        return minDouble; 
    }
    
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "First" << endl;
    cout << "Минимальное значение (int): " << fmax('i', 3, 10, 255, 1024) << endl;
    cout << "Минимальное значение (double): " << fmax('d', 3, 10.5, 255.2, 1024.8) << endl;

    cout << "Second" << endl;
    cout << "Минимальное значение (int): " << fmax('i', 4, -12, -325, 34524, -123) << endl;
    cout << "Минимальное значение (double): " << fmax('d', 4, -10.5, 255.2, -1024.8, 2122) << endl;

    cout << "Third" << endl;
    cout << "Минимальное значение (int): " << fmax('i', 2, 10, 255) << endl;
    cout << "Минимальное значение (double): " << fmax('d', 2, 10.5, 255.2) << endl;
    return 0;
}