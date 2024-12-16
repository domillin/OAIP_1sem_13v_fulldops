#include <iostream>
#include <bitset>
using namespace std;
void toBinary(int n,...) {
    int* p = &n;

    for (int i = 1; i <= n; i++){
    cout << "Число " << *(++p) << " в двоичной системе: "
        << bitset<12>(*(++p)) << endl;
    }
}
int main() {
    setlocale(LC_ALL, "ru");

    cout << "first call:" << endl;
    toBinary( 3, 10, 255, 1024 );
    cout << "second call:"<<endl;
    toBinary(2,1234, 124);
    cout << "third call:" << endl;
    toBinary(1, 19);
    return 0;
}
