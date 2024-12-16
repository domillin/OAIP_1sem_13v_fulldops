#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	int a, b, c,count=0,i=0,m;
	cout << "¬ведите а ";
	cin >> a;
	cout << "¬ведите m ";
	cin >> m;
	b = a;
	while (a > 9) {
		a /= 10;
		count++;
	}
	int* arr= new int [count];
	while (b > 9) {
		c = b % 10;
		if(c%m==0){
			*(arr + i) = c;
			i++;
			b /= 10;
		}
		else {
			b /= 10;
		}
	}
	if(b < 9) {
		if(b % m==0);
		*(arr + i) = b;
		
		
	}
	cout << "Ёлементы массива: " << endl;
	for (int i = 0; i < count; i++) {
		cout << *(arr + i) << " ";
	}
	delete[] arr;
}