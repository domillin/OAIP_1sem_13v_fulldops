#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n = 200, a = 1, b = 3;
	double h, s = 0, x;
	x = a;
	h = (b - x) / n;
	while (x < (b - h)) {
		s = s + h * ((pow(x, 3) - 3) + (pow(x + h, 3) - 3)) / 2;
		x = x + h;
	}
	cout << s;
}
//вариант 1 номер 5.1