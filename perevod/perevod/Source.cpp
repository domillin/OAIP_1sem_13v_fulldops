#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = { 1, 1, 2, 3, 3, 4 };

    auto it = unique(numbers.begin(), numbers.end());

    // Удаление дублирующихся элементов
    numbers.erase(it, numbers.end());

    for (int num : numbers) {
        cout << num << " ";  // Вывод: 1 2 3 4
    }

    return 0;
}
