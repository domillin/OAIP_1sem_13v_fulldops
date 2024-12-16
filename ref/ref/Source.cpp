#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    setlocale(LC_ALL, "ru");
    int a = 9, b = 1, c[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, d = 10, e = 3, x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const int count = 10;

    auto start = high_resolution_clock::now();
    
    for (int i = 1; i < count - 3; i += 4) {
        c[i] = (i % x[i]);
        c[i + 1] = ((i + 1) % x[i + 1]);
        c[i + 2] = ((i + 2) % x[i + 2]);
        c[i + 3] = ((i + 3) % x[i + 3]);
    }
 
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Время выполнения: " << duration.count() << " микросекунд" << endl;

}