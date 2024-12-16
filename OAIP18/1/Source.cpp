#include <iostream>
#include <cmath>
using namespace std;

int f1(const char* s, int a, int b, double e) {
    cout << s << endl;
    double x;
    double bb = b;
    double aa = a;
    while (abs(aa - bb) > 2 * e) {
        x = (aa + bb) / 2;
        if ((pow(x, 2) + 4*x - 2) * (pow(aa, 2) + 4*aa - 2) <= 0) {
            bb = x;
        }
        else {
            aa = x;
        }

    }
    cout << x << endl;
    return 0;
}
int f2(const char* s, int a, int b, double e) {
    cout << s << endl;
    double x;
    double bb = b;
    double aa = a;
    while (abs(aa - bb) > 2 * e) {
        x = (aa + bb) / 2;
        if ((sin(x) + 0.1) * (sin(aa) + 0.1) <= 0) {
            bb = x;
        }
        else {
            aa = x;
        }

    }
    cout << x;
    return 0;
}

void callfun(const char* s, int (*f)(const char*, int, int, double), int a, int b, double e) {
    f(s, a, b, e);
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, b;
    double e = 0.001;
    cout << "¬ведите a: ";
    cin >> a;
    cout << "¬ведите b: ";
    cin >> b;
    callfun("Cчитаем первое выражение", f1, a, b, e);
    callfun("Cчитаем второе выражение", f2, a, b, e);
}