#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    FILE* inputFile;
    if (fopen_s(&inputFile, "fileA.txt", "r") != 0) {
        cerr << "Ошибка открытия файла fileA.txt!" << endl;
        return 1;
    }

    int* numbers = nullptr; 
    int capacity = 100; 
    int size = 0;      
    numbers = (int*)malloc(capacity * sizeof(int)); 
    if (!numbers) {
        cerr << "Ошибка выделения памяти!" << endl;
        fclose(inputFile);
        return 1;
    }

    int number;
    while (fscanf_s(inputFile, "%d", &number) == 1) {
        numbers[size++] = number;
    }
    fclose(inputFile);
    sort(numbers, numbers + size);

    
    int* result = (int*)malloc(size * sizeof(int));
    if (!result) {
        cerr << "Ошибка выделения памяти для результирующего массива!" << endl;
        free(numbers);
        return 1;
    }

    int resultSize = 0;
    for (int i = 0; i < size;) {
        if (numbers[i] == numbers[i + 1] && numbers[i + 2]==numbers[i+1]) {
            result[resultSize] = numbers[i];
            resultSize++;
            i += 3;
        }
        else {
            i++;
        }
    }
    free(numbers);
    FILE* outputFile;
    if (fopen_s(&outputFile, "fileB.txt", "w") != 0) {
        cerr << "Ошибка открытия файла fileB.txt!" << endl;
        free(result);
        return 1;
    }

    for (int i = 0; i < resultSize; i++) {
        fprintf(outputFile, "%d\n", result[i]);
    }
    fclose(outputFile);
    free(result);

    cout << "Файл fileB.txt успешно создан." << endl;
    return 0;
}
