#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int k;
    cin >> k;
    vector<char> arr(k);
    for (int i = 0; i < k; i++) {
       cin >> arr[i];
    }
    // Сортируем массив от меньшего к большему
    sort(arr.begin(), arr.end());
    // Выводим символы, которые встречаются один раз
    cout << "Символы, которые встречаются один раз:" <<endl;
    for (int i = 0; i < arr.size(); i++) {
        if ((i == 0 || arr[i] != arr[i - 1]) && (i == arr.size() - 1 || arr[i] != arr[i + 1])) {
           cout << arr[i] << ' ';
        }
    }
    cout<<endl;
}