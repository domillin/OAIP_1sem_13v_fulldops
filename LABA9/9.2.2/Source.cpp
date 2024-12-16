#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double n = 200, a = 2, b = 7, i = 1;
	double h, s = 0, s1 = 0, s2 = 0, x;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	while (i < n) {
		s2 = s2  + pow(sin(x), 2)+1;
		x = x + h;
		s1 = s1 + pow(sin(x), 2)+1;
		x = x + h;
		i = i + 1;
	}
	s = (h * (1 + pow(sin(a), 2) + 4 * (1 + pow(sin(a + h), 2)) + 4 * s1 + 2 * s2 + (1 + pow(sin(b), 2)))) / 3;
	cout << s;
}
//через параболы вар 15 2