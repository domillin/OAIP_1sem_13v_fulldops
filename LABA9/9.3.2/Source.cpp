#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n = 200, a = 1, b = 3, i = 1;
	double h, s = 0, s1 = 0, s2 = 0, x;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	while (i < n) {
		s2 = s2 + pow(x, 3) - 3;
		x = x + h;
		s1 = s1 + pow(x, 3) - 3;
		x = x + h;
		i = i + 1;
	}
	s = (h * (pow(a, 3)-3 + 4 * (pow(a + h, 3))-3 + 4 * s1 + 2 * s2 + (pow(b, 3)-3))) / 3;
	cout << s;
}
//через параболы вар 1 2