#include <iostream>
#include <vector>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
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
	cout << "Обычный массив:" << endl;
	for (int i = 0; i < k; i++) {
		
		cout << posl[i]<<" ";
	}
	if (k <= 1) {
		cout << "Действие нельзя выполнить"<<endl;

	}
	else {
		int sum = posl[0];
		for (int i = 1; i < k; i++) {
			sum += posl[i];
			posl[i] = sum;
		}
	}
	cout << endl;
	cout << "Модифицированный массив:" << endl;
	for (int i = 0; i < k; i++) {
		
		cout << posl[i]<<" ";
	}
}