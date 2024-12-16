#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double e = 0.0001, x, a = -1000, b = 1001;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((exp(x) + x - 4) * (exp(a) + a - 4) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << x;
}