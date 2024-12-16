#include <iostream>
#include <cstdlib> // Для srand и rand
#include <ctime>   // Для time
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int row, col, m = 0, n, x;
    srand(static_cast<unsigned int>(time(0)));//инициализируем генератор случайных чисел
    cout << "Выберете действие: 1 - операции перевода с двумерным массивом. 2 - операции перевода с одномерным массивом. 3 - операции перевода с 3-х мерным массивом";
    cout << endl << "Вы выбрали вариант: ";
    cin >> x;
    switch (x) {
    case(1):
    {
        cout << "Введите количество строк двухмерного массива: ";
        cin >> row;
        cout << "Введите количество столбцов двухмерного массива: ";
        cin >> col;
        cout << endl;
        //память для одномерного массива
        int* d1 = new int[row * col];

        // создаем массив указателей
        int** d2 = new int* [row];
        for (int i = 0; i < row; ++i) {
            d2[i] = new int[col]; // выделяем память для каждого ряда
        }

        //заполняем массив случайными числами
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                d2[i][j] = rand() % 100;
            }
        }

        //вывод двухмерного массива
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << d2[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        int zz;
        cout << "Выберите: 1 - перевод двумерного массива в одномерный. 2 - перевод двумерного массива в трехмерный." << endl;
        cout << "Вы выбрали вариант: ";
        cin >> zz;
        switch (zz) {
        case(1): {
            m = 0;
            //перевод двумерного массива в одномерный
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < col; k++) {
                    d1[m] = d2[i][k];
                    m++;
                }
            }
            cout << "Одномерный массив: " << endl;
            //вывод одномерного массива
            for (int i = 0; i < row * col; i++) {
                cout << d1[i] << " ";
            }

            // Освобождаем память
            for (int i = 0; i < row; ++i) {
                delete[] d2[i]; // освобождаем память для каждого ряда
            }
            delete[] d2; //оОсвобождаем память для массива указателей

            return 0;
            break;
        }
        case(2): {
            m = 0;
            //перевод двумерного массива в одномерный
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < col; k++) {
                    d1[m] = d2[i][k];
                    m++;
                }
            }
            cout << endl;
            int depth3, row3, col3, n;
            m = 0;
            n = row * col;
            cout << "Введите количество слоев (глубина) трехмерного массива: ";
            cin >> depth3;
            cout << "Введите количество строк: ";
            cin >> row3;
            cout << "Введите количество столбцов: ";
            cin >> col3;
            if (col3 * row3 * depth3 < n) {
                cout << "Действие невозможно. Элементов двумерного массива больше, чем трехмерного.";
            }
            else {
                // создаем массив указателей для глубины
                int*** d3 = new int** [depth3];
                for (int i = 0; i < depth3; ++i) {
                    d3[i] = new int* [row3]; // выделяем память для строк в каждом слое
                    for (int j = 0; j < row3; ++j) {
                        d3[i][j] = new int[col3]; // выделяем память для столбцов в каждой строке
                    }
                }
                for (int j = 0; j < depth3; j++) {

                    for (int k = 0; k < row3; k++) {
                        for (int i = 0; i < col3; i++) {
                            if (m >= n) {
                                d3[j][k][i] = 0;
                            }
                            else {
                                d3[j][k][i] = d1[m];
                            }
                            m++;
                        }
                    }
                }
                for (int i = 0; i < depth3; ++i) {
                    cout << "Слой " << i + 1 << ":" << endl;
                    for (int j = 0; j < row3; ++j) {
                        for (int k = 0; k < col3; ++k) {
                            cout << d3[i][j][k] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }

                for (int i = 0; i < depth3; ++i) {
                    for (int j = 0; j < row3; ++j) {
                        delete[] d3[i][j];
                    }
                    delete[] d3[i];
                }
                delete[] d3;

                delete[] d1;


                for (int i = 0; i < row; ++i) {
                    delete[] d2[i];
                }
                delete[] d2;

                return 0;
            }
            break;
        default: {
            cout << "Недопустимое значение.";
            break;
        }

               break;
        }
               
        }


        break;
    }
    case(2): {
        m = 0;
        int z;
        cout << "Выберите вариант: 1 - перевод одномерного массива в двумерный массив. 2 - перевод одномерного массива в трехмерный массив.";
        cout << endl << "Вы выбрали вариант: ";
        cin >> z;
        switch (z) {
        case(1): {
            m = 0;
            cout << "Введите количество элементов одномерного массива: ";
            cin >> n;
            int* d1 = new int[n];
                cout << "Введите количество строк двухмерного массива: ";
                cin >> row;
                cout << "Введите количество столбцов двухмерного массива: ";
                cin >> col;
            if (row * col < n) {
                cout << "Элементов больше, чем доступно ячеек в двумерном. Действие невозможно.";
            }
            else {
                // создаем массив указателей
                int** d2 = new int* [row];
                for (int i = 0; i < row; ++i) {
                    d2[i] = new int[col]; // выделяем память для каждого ряда
                }

                //заполняем элеименты массива случайными числами
                for (int i = 0; i < n; i++) {
                    d1[i] = rand() % 100;
                }
                cout << "Одномерный массив: " << endl;
                //выводим одномерный массив ()
                for (int i = 0; i < n; i++) {
                    cout << d1[i] << " ";
                }
                cout << endl;
                //заполняем двумерный массив
                for (int i = 0; i < row; i++) {
                    for (int k = 0; k < col; k++) {
                        //если же элементов двумерного массива больше, чем одномерного, то заполняем их нулями
                        if (m >= n) {
                            d2[i][k] = 0;
                        }
                        else {
                            d2[i][k] = d1[m];
                        }
                        m++;
                    }
                }
                cout << "Двумерный массив: " << endl;
                //вывод двухмерного массива
                for (int i = 0; i < row; ++i) {
                    for (int j = 0; j < col; ++j) {
                        cout << d2[i][j] << " ";
                    }
                    cout << endl;
                }

                // освобождаем память
                for (int i = 0; i < row; ++i) {
                    delete[] d2[i];
                }
                delete[] d2;
                delete[] d1;

                return 0;
            }
            break;
        }
        case(2): {
            cout << "Введите количество элементов одномерного массива: ";
            cin >> n;
            int* d1 = new int[n];
            //заполняем элеименты массива случайными числами
            for (int i = 0; i < n; i++) {
                d1[i] = rand() % 100;
            }

            //выводим одномерный массив ()
            for (int i = 0; i < n; i++) {
                cout << d1[i] << " ";
            }
            cout << endl;
            int depth;
            m = 0;
            cout << "Введите количество слоев (глубина) трехмерного массива: ";
            cin >> depth;
            cout << "Введите количество строк: ";
            cin >> row;
            cout << "Введите количество столбцов: ";
            cin >> col;
            if (col * row * depth < n) {
                cout << "Элементов больше, чем доступно ячеек в трехмерном. Действие невозможно.";
            }
            else {
                // создаем массив указателей для глубины
                int*** d3 = new int** [depth];
                for (int i = 0; i < depth; ++i) {
                    d3[i] = new int* [row]; // выделяем память для строк в каждом слое
                    for (int j = 0; j < row; ++j) {
                        d3[i][j] = new int[col]; // выделяем память для столбцов в каждой строке
                    }
                }
                for (int j = 0; j < depth; j++) {

                    for (int k = 0; k < row; k++) {
                        for (int i = 0; i < col; i++) {
                            if (m >= n) {
                                d3[j][k][i] = 0;
                            }
                            else {
                                d3[j][k][i] = d1[m];
                            }
                            m++;
                        }
                    }
                }
                //вывод 3-х мерного массива
                for (int i = 0; i < depth; ++i) {
                    cout << "Слой " << i + 1 << ":" << endl;
                    for (int j = 0; j < row; ++j) {
                        for (int k = 0; k < col; ++k) {
                            cout << d3[i][j][k] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                for (int i = 0; i < depth; ++i) {
                    for (int j = 0; j < row; ++j) {
                        delete[] d3[i][j];
                    }
                    delete[] d3[i];
                }
                delete[] d3;
            }
            delete[] d1;
            return 0;
            break;
        }
        default: {
            cout << "Недопустимое значение.";
            break;
        }
        }
        break;
    }
    case(3): {
        //создаем массивы
        int depth;
        m = 0;
        cout << "Введите количество слоев (глубина) трехмерного массива: ";
        cin >> depth;
        cout << "Введите количество строк: ";
        cin >> row;
        cout << "Введите количество столбцов: ";
        cin >> col;

        // создаем массив указателей для глубины
        int*** d3 = new int** [depth];
        for (int i = 0; i < depth; ++i) {
            d3[i] = new int* [row]; // выделяем память для строк в каждом слое
            for (int j = 0; j < row; ++j) {
                d3[i][j] = new int[col]; // выделяем память для столбцов в каждой строке
            }
        }
        //заполняем массив случайными числами
        for (int i = 0; i < depth; ++i) {
            for (int j = 0; j < row; ++j) {
                for (int k = 0; k < col; ++k) {
                    d3[i][j][k] = rand() % 100;
                }
            }
        }

        //вывод 3-х мерного массива
        for (int i = 0; i < depth; ++i) {
            cout << "Слой " << i << ":" << endl;
            for (int j = 0; j < row; ++j) {
                for (int k = 0; k < col; ++k) {
                    cout << d3[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        int y;
        cout << "Выберите вариант: 1 - перевод трехмерного массива в одномерный массив. 2 - перевод трехмерного массива в двумерный массив.";
        cout << endl << "Вы выбрали вариант: ";
        cin >> y;
        switch (y) {
        case(1): { //перевод 3 в 1 +
            int* d1 = new int[row * col * depth];
            for (int i = 0; i < depth; ++i) {
                for (int j = 0; j < row; ++j) {
                    for (int k = 0; k < col; ++k) {
                        d1[m] = d3[i][j][k];
                        m++;
                    }
                }
            }
            for (int i = 0; i < row * depth * col; i++) {
                cout << d1[i] << " ";
            }
            break;
            delete[] d1;
            for (int i = 0; i < depth; ++i) {
                for (int j = 0; j < row; ++j) {
                    delete[] d3[i][j];
                }
                delete[] d3[i];
            }
            delete[] d3;
        }
        case(2): { // 3 в 2
            //считаем кол-во элементов трехмерного массива
            int el, row2, col2, p = 0, pp = 0, ppp = 0;
            el = row * col * depth;
            cout << "Введите количество строк, но учтите, что элементов, которые будут там размещены = " << el << " :";
            cin >> row2;
            cout << "Введите количество столбцов, но учтите, что элементов, которые будут там размещены = " << el << " :";
            cin >> col2;
            if (col * row * depth > col2 * row2) {
                cout << "Действие невозможно, так как количество элементов трехмерного превышает количество ячеек двумерного";
            }
            else {
                // создаем массив указателей 
                int** d2 = new int* [row2];
                for (int i = 0; i < row2; ++i) {
                    d2[i] = new int[col2]; // выделяем память для каждого ряда
                }

                //переводим 3-х мерный в одномерный
                int* d1 = new int[row * col * depth];
                for (int i = 0; i < depth; ++i) {
                    for (int j = 0; j < row; ++j) {
                        for (int k = 0; k < col; ++k) {
                            d1[m] = d3[i][j][k];
                            m++;
                        }
                    }
                }

                //одномерный в двумерный
                m = 0;
                for (int i = 0; i < row2; i++) {
                    for (int k = 0; k < col2; k++) {
                        //если же элементов двумерного массива больше, чем одномерного, то заполняем их нулями
                        if (m >= row * col * depth) {
                            d2[i][k] = 0;
                        }
                        else {
                            d2[i][k] = d1[m];
                        }
                        m++;
                    }
                }

                //вывод
                for (int i = 0; i < row2; ++i) {
                    for (int j = 0; j < col2; ++j) {
                        cout << d2[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            break;
        }
        default: {
            cout << "Недопустимое значение.";
            break;
        }
        }
        for (int i = 0; i < depth; ++i) {
            for (int j = 0; j < row; ++j) {
                delete[] d3[i][j];
            }
            delete[] d3[i];
        }
        delete[] d3;
        return 0;
    }
    default: {
        cout << "Недопустимое значение.";
        break;
    }
    }

}
