#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int k;
	cout << "Введите порядок матрицы: ";
	cin >> k;
	
	int** array = new int* [k];
	for (int i = 0; i < k; ++i) {
		array[i] = new int[k]; 
	}
	int i = 0;
	int j = 0;
	int m = 1;
	while (j < k) {
		i = 0;
		
		while (i < k) {
			array[i][j] = m;
			m++;
			
			if (m > k) {
				m = 1;
			}
			i++;
		}
		j++;
		m++;
	}
	cout << "Матрица латинский квадрат: " << endl;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cout << array[i][j] << "    ";
		}
		cout << endl;
	}
}