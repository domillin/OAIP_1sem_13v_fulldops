#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    cout << "������� ���������� ����: ";
    int k, week;
    cin >> k;
    vector<char> weeks(k);
    week = k / 7;
    double max_sum = 0;
    int max_week_start = 0;
    int s;
    for (int i = 0; i < k; i++) {
        cout << "���� " << i + 1<<": ";
        cin >> s;
        weeks[i] = s;
    }
    for (int i = 0; i < k; i += 7) {
        double current_sum = 0;
        // ��������� 7 ����
        for (int j = 0; j < 7; ++j) {
            int m = 0;
            m = weeks[i + j];
            current_sum += m;
        }
        // ���������, �������� �� ������� ����� ������������
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_week_start = i;
        }
    }
    cout << "������ � ���������� ����������� ������� ���������� � ���: " << max_week_start + 1 << endl;
    return 0;
}