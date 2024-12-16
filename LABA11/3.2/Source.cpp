#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, p, n, x, sum = 0, y, summ = 0,Bf,B,q,m,z,summm=0;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	cout << "Введите число p ";
	cin >> p;
	cout << "Введите число n ";
	cin >> n;
	cout << "Введите число B ";
	cin >> B;
	cout << "Введите число q ";
	cin >> q;
	cout << "Введите число m ";
	cin >> m;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B=" << tmp << endl;
	if (n!=m||q<=m) {
		cout << "Недопустимые значения. Значения должны соответствовать требованиям: n = m; q > m, q != m";
	}
	else {
		A = A >> p;
		for (int i = 0; i < n; i++) {
			x = pow(2, i);
			sum += x;
		}
		A = A ^ sum;
		A = A & sum;
		Bf = B;
		B = B >> q - m - 1;
		B = B >> m;
		B = B << m;
		B = B | A;
		B = B << q - m - 1;
		for (int i = 0; i < q - m - 1; i++) {
			y = pow(2, i);
			summ += y;
		}
		Bf = Bf & summ;
		B = B | Bf;
		cout << B << endl;
		_itoa_s(B, tmp, 2);
		cout << "B=" << tmp << endl;
	}
}