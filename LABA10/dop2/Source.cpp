#include <iostream>
#include <vector>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Введите количество дней: ";
    int k, week;
    cin >> k;
    vector<char> weeks(k);
    week = k / 7;
    double max_sum = 0;
    int max_week_start = 0;
    int s;
    for (int i = 0; i < k; i++) {
        cout << "День " << i + 1<<": ";
        cin >> s;
        weeks[i] = s;
    }
    for (int i = 0; i < k; i += 7) {
        double current_sum = 0;
        // Суммируем 7 дней
        for (int j = 0; j < 7; ++j) {
            int m = 0;
            m = weeks[i + j];
            current_sum += m;
        }
        // Проверяем, является ли текущая сумма максимальной
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_week_start = i;
        }
    }
    cout << "Неделя с наибольшим количеством осадков начинается с дня: " << max_week_start + 1 << endl;
    return 0;
}