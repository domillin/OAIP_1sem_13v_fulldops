#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A, B, p, n, sum = 0, x, b,y, m, q,bf,summ=0;
	char tmp[33];
	cout << "������� ����� � ";
	cin >> A;
	cout << "������� ����� p ";
	cin >> p;
	cout << "������� ����� n ";
	cin >> n;
	cout << "������� ����� B ";
	cin >> B;
	cout << "������� ����� q ";
	cin >> q;
	cout << "������� ����� m ";
	cin >> m;
	_itoa_s(A, tmp, 2);
	cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2);
	cout << "B=" << tmp << endl;
	if (n != m||p<=n) {
		cout << "����� ���� ������������, ���� ������, ��� ���������, ������� ���������� ������ (m=n)";
	}
	else {
		if (p > n) {
			A = A >> p - n - 1;
			for (int i = 0; i < n; i++) {
				x = pow(2, i);
				sum += x;
			}
			A = A ^ sum;
			A = A & sum;
		}
		else {
			A = A << n - p + 1;
			for (int i = 0; i < n; i++) {
				x = pow(2, i);
				sum += x;
			}
			A = A ^ sum;
			A = A & sum;
		}
		bf = B;
		for (int i = 0; i < q - m - 1; i++) {
			y = pow(2, i);
			summ += y;
		}
		bf = bf & summ;
		if (q > m) {
			B = B >> q - 1;
			B = B << m;
			B = B | A;
			B = B << q - m - 1;
			B = B | bf;
			cout << B << endl;
			_itoa_s(B, tmp, 2);
			cout << "B=" << tmp << endl;
		}
		else {
			cout << "�� �� ����� �������� " << m << " ����� � ������� " << q << ", ��� ��� " << m << " > " << q << ", ��� ������� �������������� ���� � ��������� �� ����� ���������";
		}
	}
	
}