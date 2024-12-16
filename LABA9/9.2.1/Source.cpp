#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n = 200, a = 2, b = 7;
	double h, s = 0, x;
	x = a;
	h = (b - x) / n;
	while (x < (b - h)) {
		s = s + h * ((pow(sin(x),2)+1)+(pow(sin(x+h),2)+1)) / 2;
		x = x + h;
	}
	cout << s;
}
//вариант 15 номер 5.1