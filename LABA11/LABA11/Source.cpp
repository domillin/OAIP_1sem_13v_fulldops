#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, B,ac,acc,bc;
	char tmp[33];
	cout << "������� ����� � ";
	cin >> A;
	cout << "������� ����� B ";
	cin >> B;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B=" << tmp << endl;
	ac = A >> 5;
	acc = ac & 3;
	acc = acc << 5;
	bc = B | acc;
	cout << "����� B = " << bc<<endl;
	_itoa_s(bc, tmp, 2);
	cout << "B=" << tmp << endl;
}