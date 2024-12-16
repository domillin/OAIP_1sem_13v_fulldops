#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, B, ac, n, m=0, p, sum = 0;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	cout << "Введите число p ";
	cin >> p;
	cout << "Введите число n ";
	cin >> n;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	ac = A;
	for (int i = 0; i < p; i++) {
		m += pow(2, i);
	}
	ac = ac & m;
	A = A >> p;
	for (int i = 0; i < n; i++) {
		sum += pow(2, i);
	}
	A = A | sum;
	A = A << p;
	A = A | ac;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
}
