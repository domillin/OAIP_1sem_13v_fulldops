#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int max = 0, num = 0, buf;
    int* ptr = &buf;
    int ar[] = { 1,-3,5,7,2,-5,-7,-10,7,4,6 };
    int ra[] = { 2,3,1,5,6,8,2,1,32,5,65,234,23,1,1,3,4,5,3,2 };
    max = *ar;
    for (int i = 0; i < size(ar); i++) {
        if (max < *(ar + i)) {
            max = *(ar + i);
        }
    }
    cout << max << endl;
    for (int i = 0; i < size(ra); i++) {
        if (max == *(ra + i)) {
            num++;
        }
    }
    if (num != 0) {
        cout << "Массив содержит максимальный элемент!";
    }
    else {
        cout << "Массив не содержит максимальный элемент";
    }
}