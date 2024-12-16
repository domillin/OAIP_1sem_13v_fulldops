#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, b,sum=0;
	char tmp[33];
	cout << "Введите число А ";
	cin >> A;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	A = A >> 2;
	
	for (int i = 1; i <= 11; i++) {
		b = A;
		A = A >> 1;
		A = A << 1;
		if (A == b) {
			sum += 1;
		}
		A = A >> 1;
		b = b >> 1;
	}
	cout << sum;
}