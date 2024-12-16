#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int k,rows,cols;
    
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;


    int** array = new int* [rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение массива случайными числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
			*(*(array + i) + j) = rand() % 100; // Случайные числа от 0 до 99
        }
    }
	cout << "Матрица: " << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << *(*(array+i)+j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	int max = 0;
	int i,j=0;
	int sum = 0;
	while (j < cols) {
		i = 0;
		max = 0;
		while (i <rows) {
			max += *(*(array + i) + j);
			i++;
		}
		i = 0;
		while (i < rows) {
			if (*(*(array + i) + j) > max - *(*(array + i) + j)) {
				sum++;
				cout << "Max in column " << j+1 << " = " << *(*(array + i) + j) << endl;
			}
			
			i++;
		}
		j++;
	}
	cout << endl;
	
	cout << "MAX= " << sum << endl;

}
//+