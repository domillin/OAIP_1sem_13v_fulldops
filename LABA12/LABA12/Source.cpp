#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int sum=0;
    int ar[14] = { 1,2,3,4,2,1,23,4,3223,23,4,3,2,1 };

    sort(begin(ar), end(ar));
    for (int i = 0; i < 14; i++) {
        
        if (*(ar + i) != *(ar + i + 1)) {
            sum++;
        }
    }
    cout << endl << "Было найдено " << sum << " уникальных элементов";
}