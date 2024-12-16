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
        if ((cos(x) + x - 7) * (cos(aa) + aa - 7) <= 0) {
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
        if ((exp(x) -(1/x)) * (exp(aa) -(1/aa)) <= 0) {
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