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
#include <algorithm>

using namespace std;

int main() {
    string str;

    while (cin >> str) {
        auto it = str.begin(), end = str.end();
        while (it != end && (*it == '3' || *it == '4')) {
            it++;
        }
        while (it != end && (*it == '1' || *it == '2')) {
            it++;
        }
        if (it != end) {
            cout << '0' << endl;
        } else {
            cout << '1' << endl;
        }
    }

    return 0;
}