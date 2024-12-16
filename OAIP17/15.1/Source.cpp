#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int* createArray(int size) {
	return new int[size]; // Возвращаем указатель на новый массив
}
int searchMin(int mass, int* array) {
	int min = 1000,number=0,sum=0;
	for (int i = 0; i<mass; i++) {
		if (min > array[i]) {
			min = array[i];
		}
	}
	for (int i = mass - 1; i >= 0; i--) {
		if (array[i] == min) {
			number = i;
			break;
		}
	}
	for (int i = number+1; i <mass; i++) {
		sum += array[i];
	}
	cout << "min=" << min << endl;
	cout << "sum=" << sum;
	return 0;
}
void printArray(const int* array, int size) {
	cout << "Случайные значения в массиве: ";
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main() {
	srand(static_cast<unsigned int>(time(0)));
	setlocale(LC_ALL, "ru");
	int mass;
	cin >> mass;
	int* array = createArray(mass);
	for (int i = 0; i < mass; ++i) {
		array[i] = rand() % 20 - 10; // Генерация случайного числа
	}
	printArray(array, mass);
	searchMin(mass,array);
	

}