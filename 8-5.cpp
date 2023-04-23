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
#include <typeinfo>
#include<chrono>

using namespace std;
using namespace std::chrono;

year_month_day get(int d, int m, int y) {
    if (m == 1) return January/d/y;
    if (m == 2) return February/d/y;
    if (m == 3) return March/d/y;
    if (m == 4) return April/d/y;
    if (m == 5) return May/d/y;
    if (m == 6) return June/d/y;
    if (m == 7) return July/d/y;
    if (m == 8) return August/d/y;
    if (m == 9) return September/d/y;
    if (m == 10) return October/d/y;
    if (m == 11) return November/d/y;
    if (m == 12) return December/d/y;
    _Exit(0);
}

int main() {
    int y0,m0,d0;
    int y1,m1,d1;
    char c;
    
    int sum = 0;
    if (!(cin >> y0>>c>>m0>>c>>d0)) {
        cout << sum << endl;
        return 0;
    }
    
    year_month_day t0 = get(d0, m0, y0);
    
    while(cin >> y1>>c>>m1>>c>>d1) {
        year_month_day t1 = get(d1, m1, y1);
        sum += abs((sys_days{t1} - sys_days{t0}).count());
        t0 = t1;
    }
    
    cout << sum << endl;
    
    return 0;
}