#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, B,p,n,sum=0,x;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	cout << "Введите число p ";
	cin >> p;
	cout << "Введите число n ";
	cin >> n;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	B = A;
	A = A >> p;
	A = A >> n;
	A = A << p + n;
	for (int i = 0; i < p; i++) {
		x = pow(2, i);
		sum += x;
	}
	B = B & sum;
	A = A | B;
	cout << A << endl;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
}