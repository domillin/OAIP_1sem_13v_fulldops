#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double e = 0.0001, x, a = -1000, b = 1001;

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if ((pow(x,3) + x - 3) * (pow(a,3) + a - 3) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << x;
}