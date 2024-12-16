#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
int main() {
	float x;
	double stroka, stolb, strokap;
	stroka = x / 8;
	stolb = int(x) % 8;
	strokap = ceil(stroka);
	if (stolb == 1) {
		char letter = 'A';
		cout << strokap << letter;
	}
	if (stolb == 2) {
		char letter = 'B';
		cout << strokap << letter;
	}
	if (stolb == 3) {
		char letter = 'C';
		cout << strokap << letter;
	}
	if (stolb == 4) {
		char letter = 'D';
		cout << strokap << letter;
	}
	if (stolb == 5) {
		char letter = 'E';
		cout << strokap << letter;
	}
	if (stolb == 6) {
		char letter = 'F';
		cout << strokap << letter;
	}
	if (stolb == 7) {
		char letter = 'G';
		cout << strokap << letter;
	}
	if (stolb == 8) {
		char letter = 'H';
		cout << strokap << letter;
	}
}