#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Введите элементы массива: "<<endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int max = 1; // Максимальное количество подряд идущих одинаковых элементов
    int current = 1; // Текущее количество подряд идущих одинаковых элементов

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            current++; 
        }
        else {
            if (current > max) {
                max = current;
            }
            current = 1; 
        }
    }

    // Проверяем последний подсчет
    if (current > max) {
        max = current;
    }

    cout << "Наибольшее количество подряд идущих одинаковых элементов: " << max << endl;
}