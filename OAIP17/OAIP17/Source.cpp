#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int* createArray(int size) {
	return new int[size]; // Возвращаем указатель на новый массив
}
void printArray(const int* array, int size) {
	cout << "Случайные значения в массиве: ";
	for (int i = 0; i < size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int* findElements(const int* array, int size, int& mass2) {

	for (int i = 1; i < size; i += 2) {
		if (array[i] > 0) {
			mass2++;
		}
	}
	int* arrayB = new int[mass2];
	int k = 0;
	for (int i = 1; i < size; i += 2) {
		if (array[i] > 0) {
			arrayB[k] = array[i];
			k++;
		}
	}
	return arrayB;
}
int main() {
	srand(static_cast<unsigned int>(time(0)));
	setlocale(LC_ALL, "ru");
	int mass = 20;	
	int mass2 = 0;
	int summ = 0;
	int* array = createArray(mass);
	for (int i = 0; i < mass; ++i) {
		array[i] = rand() % 20-10; // Генерация случайного числа
	}
	printArray(array, mass);
	int* arrayB=findElements(array, mass, mass2);
	cout << endl;
	for (int i = 0; i < mass2; ++i) {
		summ += arrayB[i] * arrayB[i];
	}
	cout << summ;

}