#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    ifstream f1("f1.txt");
    ofstream f2("f2.txt");

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }
    int cols;
    f1 >> cols;


    vector<vector<double>> matrix;
    vector<double> row;

    double value;

    while (f1 >> value) {
        row.push_back(value);
        if (row.size() == cols) {
            matrix.push_back(row);
            row.clear();
        }
    }


    if (matrix.empty() || matrix[0].size() != cols) {
        cerr << "Ошибка чтения матрицы" << endl;
        return 1;
    }

    
    f2 << cols << endl;
    int rows = matrix.size();
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            f2 << matrix[i][j] << " ";
        }
        f2 << endl;
    }

    cout << "Транспонирование завершено." << endl;
    return 0;
}