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

bool check(string::iterator it, string::iterator end, int zero, int one) {
    int tmp_zero = 0, tmp_one = 0;
    while (it != end) {
        tmp_zero = 0;
        tmp_one = 0;
        while (it != end && (*it == '0')) {
            tmp_zero++;
            it++;
        }
        
        if (tmp_zero != zero) {
            return false;
        }
        while (it != end && (*it == '1')) {
            tmp_one++;
            it++;
        }
        if (tmp_one != one) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;

    while (cin >> str) {
        int one = 0, zero = 0;
        auto it = str.begin(), end = str.end();
        while (it != end && (*it == '0')) {
            zero++;
            it++;
        }
        while (it != end && (*it == '1')) {
            one++;
            it++;
        }
        if (check(it, end, zero, one)) {
            cout << '1' << endl;
        } else {
            cout << '0' << endl;
        }
    }

    return 0;
}