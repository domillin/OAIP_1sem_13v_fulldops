#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, n, p, x,sum=0,Af;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	cout << "Введите число p ";
	cin >> p;
	cout << "Введите число n ";
	cin >> n;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	for (int i = 0; i < n; i++) {
		x = pow(2, i);
		sum += x;
	}
	Af = A;
	if (n > p) {
		A = A >> p - 1;
		A = A << n;
		A = A | sum;
		A = A >> n - p + 1;
		cout << A;
		_itoa_s(A, tmp, 2);
		cout << "A=" << tmp << endl;
	}
	else {
		A = A >> p - 1;
		A = A << n;
		A = A | sum;
		A = A << (p - n - 1);
		A = A | Af;
		cout << A;
		_itoa_s(A, tmp, 2);
		cout << "A=" << tmp << endl;
	}
}
