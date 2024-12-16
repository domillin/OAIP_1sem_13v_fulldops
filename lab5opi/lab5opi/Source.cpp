#include <iostream> 
#include <windows.h> 

int main()
{
    using namespace std;
    setlocale(LC_CTYPE, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int k;
    unsigned char X, Y, Z;
    cout << "1 - английский, " << " 2 - русский, " << " 3 - код символа, " << " 4 - выход из программы: " << endl;
    cin >> k;
    switch (k)
    {
    case(1):
    {
        cout << "Введите букву : ";
        cin >> X;
        if (X >= 'A' && X <= 'Z' || X >= 'a' && X <= 'z')
        {
            cout << "Разница между её строчным и прописным = " << tolower(X) - toupper(X);
        }
        else
        {
            cout << "Неаправильно введены данные";
        }
        break;
    }
    case(2):
    {
        cout << "Введите букву : ";
        cin >> Y;
        if (Y >= 192 && Y <= 223 || Y >= 224 && Y <= 255 || Y == 168 || Y == 184)
        {
            cout << "Разница = " << tolower(Y) - toupper(Y);
        }
        else
        {
            cout << "Данные введены некорректно";
        }
        break;
    }
    case(3):
    {
        cout << "Введите цифру : ";
        cin >> Z;
        if (Z >= '0' && Z <= '9')
        {
            cout << "Цифра " << Z << " имеет код = " << int(Z);
        }
        else
        {
            cout << "Данные введены некорректно";
        }
        break;
    }
        case(4):
        {
            cout << "Выход из программы." << endl;
            break;
    }
        default:
        {
            cout << "Ошибка, выберите цифру(1-4)";
            break;
    }
    }
    return 0;
}
