#include <iostream>
#include <cstring>

using namespace std;

class A {
    int x;
    int y;
    public:
        A() {
            cin >> x;
            y = 0;
        }

        A(const A & v) {
            cin >> x;
            x += v.x;
            y = 1;
        }

        ~A() {
            if (y) {
                cout << x;
            }
        }
};

int main() {
    A a, b(a);

    return 0;
}