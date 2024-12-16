#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n = 200, a = 1, b = 6;
	double h, s = 0, x;
	x = a;
	h = (b - x) / n;
	while (x < (b - h)) {
		s = s + h * ((pow(x, 3) +1) + (pow(x + h, 3) + 1)) / 2;
		x = x + h;
	}
	cout << s;
}
//вариант 3 номер 5.1