#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A,B;
	cout << "������� ����� � ";
	cin >> A;
	B = A;
	A = A >> 1;
	A = A << 1;
	if (A == B) {
		cout << "����� ������";
	}
	else {
		cout << "����� ��������";
	}
	
}
/*                     2 ������
	A = A ^ 1;
	if (A == B + 1) {
		cout << "����� ������";
	}
	else {
		cout << "����� ��������";
	}*/