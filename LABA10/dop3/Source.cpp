#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "������� ���������� ��������� �������: ";
    cin >> n;

    if (n <= 0) {
        cout << "������ ������� ������ ���� �������������." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "������� �������� �������: "<<endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int max = 1; // ������������ ���������� ������ ������ ���������� ���������
    int current = 1; // ������� ���������� ������ ������ ���������� ���������

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

    // ��������� ��������� �������
    if (current > max) {
        max = current;
    }

    cout << "���������� ���������� ������ ������ ���������� ���������: " << max << endl;
}