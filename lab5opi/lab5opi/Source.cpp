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
    cout << "1 - ����������, " << " 2 - �������, " << " 3 - ��� �������, " << " 4 - ����� �� ���������: " << endl;
    cin >> k;
    switch (k)
    {
    case(1):
    {
        cout << "������� ����� : ";
        cin >> X;
        if (X >= 'A' && X <= 'Z' || X >= 'a' && X <= 'z')
        {
            cout << "������� ����� � �������� � ��������� = " << tolower(X) - toupper(X);
        }
        else
        {
            cout << "������������ ������� ������";
        }
        break;
    }
    case(2):
    {
        cout << "������� ����� : ";
        cin >> Y;
        if (Y >= 192 && Y <= 223 || Y >= 224 && Y <= 255 || Y == 168 || Y == 184)
        {
            cout << "������� = " << tolower(Y) - toupper(Y);
        }
        else
        {
            cout << "������ ������� �����������";
        }
        break;
    }
    case(3):
    {
        cout << "������� ����� : ";
        cin >> Z;
        if (Z >= '0' && Z <= '9')
        {
            cout << "����� " << Z << " ����� ��� = " << int(Z);
        }
        else
        {
            cout << "������ ������� �����������";
        }
        break;
    }
        case(4):
        {
            cout << "����� �� ���������." << endl;
            break;
    }
        default:
        {
            cout << "������, �������� �����(1-4)";
            break;
    }
    }
    return 0;
}
