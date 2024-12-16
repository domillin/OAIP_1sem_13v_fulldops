#include <iostream> 
#include <cmath> 
using namespace std;
int main() {
	double n = 200, a = 8, b = 14;
	double h, s = 0, x;
	x = a;
	h = (b - x) / n;
	while (x < (b - h)) {
		s = s + h * (2+pow(x,3) + (pow(x + h,3) + 2)) / 2;
		x = x + h;
	}
	cout << s;
}