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

class summ {
    public:
        double s;
        summ(double x = 0.0): s(x) {}
        void operator() (double x) {
            s += x;
        }      
};

int main(int argc, char const **argv) {
    vector<double> arr;
    double x;
    while (cin >> x) {
        arr.push_back(x);
    }
    
    vector<double>::iterator arr_begin = arr.begin(), arr_end;
   
    // cut last 10%
    int s = arr.size() / 10;
    arr.erase(arr_begin, arr_begin + s);
    arr_end = arr.end();
    // cut first 10%
    arr.erase(arr_end - s, arr_end);
    arr_begin = arr.begin(); arr_end = arr.end();
    
    sort(arr.begin(), arr.end());
    
    // cut last 10%
    s = arr.size() / 10;
    arr.erase(arr_begin, arr_begin + s);
    arr_end = arr.end();
    // cut first 10%
    arr.erase(arr_end - s, arr_end);
    arr_begin = arr.begin(); arr_end = arr.end();
    
    summ ans = for_each(arr_begin, arr_end, summ());
    ans.s /= arr.size();
    
    cout << fixed << setprecision(10) << ans.s;
    
    return 0;
}