#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int A,B;
	cout << "Введите число А ";
	cin >> A;
	B = A;
	A = A >> 1;
	A = A << 1;
	if (A == B) {
		cout << "Число четное";
	}
	else {
		cout << "Число нечетное";
	}
	
}
/*                     2 СПОСОБ
	A = A ^ 1;
	if (A == B + 1) {
		cout << "Число четное";
	}
	else {
		cout << "Число нечетное";
	}*/