#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

unsigned int
f(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned int n = 0;
    n = (n | a) << 8;
    n = (n | b) << 8;
    n = (n | c) << 8;
    n |= d;

    return n;
}

int main() {
    unsigned int n, a, b, c, d;
    int cnt = 0;

    cin >> hex >> n;

    while (cin >> hex >> a && cin >> hex >> b && cin >> hex >> c && cin >> hex >> d) {
        cnt += 4;

        n = f(a, b, c, d);
        cout << n << endl;

        if (cnt % 16 == 0) {
            cnt = 0;
            cin >> hex >> n;
        }
    }

    return 0;
}
