#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char a;
    cin.tie(nullptr);
    // -1 = буква
    // 0 = цифра 0
    // 1 = цифра != 0
    int flag = -1;

    while ((a = cin.get()) != EOF) {
        if (!(a >= '0' && a <= '9')) {
            if (flag == 0) {
                cout << '0';
            }
            
            flag = -1;

            cout << a;
            
            continue;
        }

        if (a == '0') {
            if (flag == -1) {
                flag = 0;
            } else if (flag == 1) {
                cout << a;
            }
        } else {
            flag = 1;
            cout << a;
        }
    }

    if (flag == 0) {
        cout << '0';
    }

    return 0;
}
