#include <iostream>
#include <vector>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int k;
	cin >> k;
	vector<int> posl(k);
	srand((unsigned)time(NULL));
	for (int i = 0; i < k; i++) {
		posl[i] = rand() % 90;
	}
	cout << "������� ������:" << endl;
	for (int i = 0; i < k; i++) {
		
		cout << posl[i]<<" ";
	}
	if (k <= 1) {
		cout << "�������� ������ ���������"<<endl;

	}
	else {
		int sum = posl[0];
		for (int i = 1; i < k; i++) {
			sum += posl[i];
			posl[i] = sum;
		}
	}
	cout << endl;
	cout << "���������������� ������:" << endl;
	for (int i = 0; i < k; i++) {
		
		cout << posl[i]<<" ";
	}
}