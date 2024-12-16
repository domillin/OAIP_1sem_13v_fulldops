#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int* createArray(int size) {
	return new int[size]; // Возвращаем указатель на новый массив
}
void printArray(const int* array, int size) {
	cout << "Случайные значения в массиве: "<<endl;
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void elements(int* array, int mass) {
	int max = 0, min = 100, firstmax = 0, lastmin = 0, sum = 0;
	for (int i = 0; i < mass; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	for (int i = 0; i < mass; ++i) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	for (int i = 0; i < mass; ++i) {
		if (array[i] == max) {
			firstmax = i;
			break;
		}
	}
	for (int i = mass-1; i >=0; i--) {
		if (array[i] == min) {
			lastmin = i;
			break;
		}
	}
	if (lastmin > firstmax) {
		for (int i = firstmax+1; i < lastmin; i++) {
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
	int mass = 5;
	srand(static_cast<unsigned int>(time(0)));
	int* array = createArray(mass);
	for (int i = 0; i < mass; ++i) {
		array[i] = rand() % 20 - 5; // Генерация случайного числа
	}
	printArray(array, mass);
	elements(array,mass);
	return 0;
}