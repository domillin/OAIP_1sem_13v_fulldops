#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int x;
	cout << "������� ���������� ����� ��� ������ (���������� �������� �������� 1-7): ";
	cin >> x;
	switch (x) {
	case(1): {
		cout << "���� ������ � ���������� ������� " << x << " - �����������.";
		break;
	}
	case(2): {
		cout << "���� ������ � ���������� ������� " << x << " - �������.";
		break;
	}
	case(3): {
		cout << "���� ������ � ���������� ������� " << x << " - �����.";
		break;
	}
	case(4): {
		cout << "���� ������ � ���������� ������� " << x << " - �������.";
		break;
	}
	case(5): {
		cout << "���� ������ � ���������� ������� " << x << " - �������.";
		break;
	}
	case(6): {
		cout << "���� ������ � ���������� ������� " << x << " - �������.";
		break;
	}
	case(7): {
		cout << "���� ������ � ���������� ������� " << x << " - �����������.";
		break;
	}
	default: {
		cout << "������ ������� �����������.";
		break;
	}
	}
	cout << endl;
	return 0;
}