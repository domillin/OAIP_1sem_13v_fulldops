#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int k;
    cin >> k;
    vector<char> arr(k+1);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    int count = 0;

    for (int i = 0; i < k;i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
    }

    cout << "Количество пар соседних элементов с одинаковыми значениями: " << count <<endl;
    return 0;
}