#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int size=10, t, count = 0, counttwo = 0, countthree = 0,max;
    // ƒинамическое выделение пам€ти под массив 
    int* C = new int[size];
    int* B = new int[size];
    srand(time(NULL));

    
    for (int i = 0; i < size; i++) {
        *(C + i) = rand() % 10;
    }
    for (int i = 0; i < size; i++) {
        *(B + i) = rand() % 10;
    }

    cout << "Ёлементы массива C: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(C + i) << " ";
    }
    cout << endl;
    cout << "Ёлементы массива B: " << endl;
    for (int i = 0; i < size; i++) {
        cout << *(B + i) << " ";
    }
    cout << endl;
tryAgain:
    max = 0;
    for (int i = 0; i < size; i++) {
        if (*(C + i) > max) {
            max = *(C + i);
        }
    }
   
    for (int i = 0; i < size; i++) {
        if (*(B + i) == max) {
            for (int k = 0; k < size; k++) {
                if (*(C + k) == max) {
                    *(C + k)=-1;
                    goto tryAgain;

                }
                else { continue; }
            }
        }
    }
    
    cout << endl;
    cout << max;
    

    delete[] C; 
    delete[] B;

}