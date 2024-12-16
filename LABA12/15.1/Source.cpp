#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int sum = 0, num = 0,buf;
    int* ptr = &buf;
    int ar[] = { 1,-3,5,7,2,-5,-7,-10,7,4,5 };
    for (int i = 0; i < size(ar); i++) {
        if (*(ar + i) < 0){
            *ptr = *(ar + num);
            *(ar + num) = *(ar + i);
            *(ar + i) = buf;
            num++;
        }
    }
    for (int i = 0; i < size(ar); i++) {
        cout << *(ar + i) << " ";
    }

   
}