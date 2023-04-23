#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cassert>

using namespace std;

class Error {
    private:
        string str;
    public:
        Error(const string &x) {
            this->str = x;
        }
        ~Error() {
            cout << str << endl;
        }
};

void f() {
    string str;

    if (cin >> str) {
        try {
            f();
        }
        catch (...) {}
        throw Error(str);
    }
    throw str;
}


int main() {
    try {
        f();
    }
    catch (...) {};

    return 0;
}