#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	double zapasUSA = 38.4e12, zern = 5e-3, kletka = 0, x=0,zernUSA,sumUSA=0, sumRUS=0, zernRUS, zapasRUS=92.8e12, zapasBY=2.3e12, sumBY=0,zernBY;
	zernUSA = zapasUSA / zern; //урожай США в зернах за 2023 год
	int a = 1;
	int i = 0;
	while (sumUSA < zernUSA) { //уже закончился урожай на этой клетке
		x = a * pow(2, i);
		sumUSA = sumUSA + x;
		if (zernUSA < sumUSA) {
			
			float x;
			double stroka, stolb, strokap;
			x = i + 1;
			stroka = x / 8;
			stolb = int(x) % 8;
			strokap = ceil(stroka);
			char letter;
			if (stolb == 1) {
				letter = 'A';
			}
			if (stolb == 2) {
				 letter = 'B';
			}
			if (stolb == 3) {
				 letter = 'C';
			}
			if (stolb == 4) {
				 letter = 'D';
			}
			if (stolb == 5) {
				 letter = 'E';
			}
			if (stolb == 6) {
				 letter = 'F';
			}
			if (stolb == 7) {
				 letter = 'G';
			}
			if (stolb == 8) {
				 letter = 'H';
			}
			cout << "Уже на клетку " << strokap << letter << " (" << x << "-яя)" << " урожая США не хватит." << endl;
		}
		i++;
	}
	i = 0;
	zernRUS = zapasRUS / zern;
	while (sumRUS < zernRUS) { //уже закончился урожай на этой клетке
		x = a * pow(2, i);
		sumRUS = sumRUS + x;
		if (zernRUS < sumRUS) {
			float x;
			double stroka, stolb, strokap;
			x = i + 1;
			stroka = x / 8;
			stolb = int(x) % 8;
			strokap = ceil(stroka);
			char letter;
			if (stolb == 1) {
				letter = 'A';
			}
			if (stolb == 2) {
				letter = 'B';
			}
			if (stolb == 3) {
				letter = 'C';
			}
			if (stolb == 4) {
				letter = 'D';
			}
			if (stolb == 5) {
				letter = 'E';
			}
			if (stolb == 6) {
				letter = 'F';
			}
			if (stolb == 7) {
				letter = 'G';
			}
			if (stolb == 8) {
				letter = 'H';
			}
				cout << "Уже на клетку " << strokap << letter << " (" << x << "-яя)" << " урожая РФ не хватит." << endl;
		}
		i++;
	}
	i = 0;
	zernBY = zapasBY / zern;
	while (sumBY < zernBY) { //уже закончился урожай на этой клетке
		x = a * pow(2, i);
		sumBY = sumBY + x;
		if (zernBY < sumBY) {
			float x;
			double stroka, stolb, strokap;
			x = i + 1;
			stroka = x / 8;
			stolb = int(x) % 8;
			strokap = ceil(stroka);
			char letter;
			if (stolb == 1) {
				letter = 'A';
			}
			if (stolb == 2) {
				letter = 'B';
			}
			if (stolb == 3) {
				letter = 'C';
			}
			if (stolb == 4) {
				letter = 'D';
			}
			if (stolb == 5) {
				letter = 'E';
			}
			if (stolb == 6) {
				letter = 'F';
			}
			if (stolb == 7) {
				letter = 'G';
			}
			if (stolb == 8) {
				letter = 'H';
			}
			cout << "Уже на клетку " << strokap << letter << " (" << x << "-яя)" << " урожая РБ не хватит." << endl;
		}
		i++;
	}
}