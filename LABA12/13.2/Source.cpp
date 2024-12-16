#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    setlocale(LC_ALL,"ru");
    int sum = 0,num=0;
    int ar[] = {7,8,9,1,2,5,3,4,6,15,2,12,3,2,4,5,10,9};
    int arr[size(ar)];   
    for (int i = 0; i < size(ar); i++) {
        sum += *(ar + i);
    }
    sum = sum / size(ar);
    cout << sum<<endl;
    for (int i = 0; i < size(ar); i++) {
        if (*(ar + i) < sum) {
            *(arr + num) = *(ar + i);
            num++;
        }
        
    }
    for (int i = 0; i < size(ar); i++) {
        if (*(ar + i) >= sum) {
            *(arr + num) = *(ar + i);
            num++;
        }

    }
    
    for (int i = 0; i < size(arr); i++) {
        cout << *(arr + i)<<" ";
    }
}