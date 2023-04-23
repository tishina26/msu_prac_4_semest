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
#include <list>

using namespace std;

int main () {
    list<int> arr;
    int x;
    while ((cin >> x) && (x != 0)) {
        arr.push_back(x);
    }
    
    int a, b, s;
    list<int>::iterator i;
    
    while (cin >> a) {
        if (a < 0) {
            a = -a;
            int s = arr.size();
            
            if ((a >= 0) && (a <= s)) {
                i = arr.begin();
                advance(i, a - 1);
                arr.erase(i);
            }
        } else {
            cin >> b;
            if (a >= 0) {
                s = arr.size();
                if (a <= s) {
                    i = arr.begin();
                    advance(i, a - 1);
                    arr.insert(i, b);
                } else {
                    arr.push_back(b);
                }
            }
        }
    }
    
    for (i = arr.begin(); i != arr.end(); i++) {
        cout << *i << endl;
    }
    
    return 0;
}