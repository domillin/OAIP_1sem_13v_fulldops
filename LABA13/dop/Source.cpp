#include <iostream>
#include <string>
//компилируется не в vs
using namespace std;
int main()
{
    cout << "s: ";
    string s;
    getline(cin, s);

    int index = 0;
    string arr[20];
    string word = "";
    for (char c : s)
    {
        if (c == ' ')
        {
            arr[index] = word;
            index += 1;
            word = "";
        }
        else
        {
            word += c;
        }
    }
    arr[index] = word; //слово - элемент
    int l = index + 1;
    string res = arr[0] + " ";
    for (int i = 1; i < l; i++)
    {
        int c = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                c += 1;
            }
        }
        if (c == 0) res += arr[i] + " ";
    }
    cout << res;
    return 0;
}
