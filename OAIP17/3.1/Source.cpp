#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int* createArray(int size) {
	return new int[size]; // Возвращаем указатель на новый массив
}
void printArray(const int* array, int size) {
	cout << "Случайные значения в массиве: " << endl;
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void elements(int* array, int mass) {
	int first = -1, last = -1, sum = 0;
	
	for (int i = 0; i < mass; ++i) {
		if (array[i] == 0) {
			first = i;
			break;
		}
	}
	for (int i = mass - 1; i >= 0; i--) {
		if (array[i] == 0) {
			last = i;
			break;
		}
	}
	if (last > first&&last>=0&&first>=0&&first!=last) {
		for (int i = first + 1; i < last; i++) {
			sum += array[i];
		}
		cout << "Summa = " << sum;
	}
	else {
		cout << "Первый максимальный элемент находится дальше последнего положительного";
	}


}

int main() {
	setlocale(LC_ALL, "ru");
	int mass = 10;
	srand(static_cast<unsigned int>(time(0)));
	int* array = createArray(mass);
	for (int i = 0; i < mass; ++i) {
		array[i] = rand() % 5 - 1; // Генерация случайного числа
	}
	printArray(array, mass);
	elements(array, mass);
	return 0;
}