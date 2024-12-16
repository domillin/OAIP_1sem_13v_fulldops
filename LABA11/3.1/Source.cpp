#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, x, sum = 0,Af;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	Af = A;
	Af = Af & 1;
	A = A >> 1;
	for (int i = 0; i < 13; i++) {
		x = pow(2, i);
		sum += x;
	}
	A = A ^ sum;
	A = A << 1;
	A = A | Af;
	cout << A<<endl;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
}
//+