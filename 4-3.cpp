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

void process(const vector<int>& v1, vector<int>& v2) {
    if ((v1.size() == 0) || (v2.size() == 0)) {
        return;
    }
    
    set<int> copy_v1(v1.begin(), v1.end());
    
    auto i = copy_v1.rbegin();
    vector<int>::iterator j = v2.begin();
    int s = v2.size();
    
    for (; i != copy_v1.rend(); i++) {
        int index = *i;
        if (index >= 0 && index < s) {
          
        
            j = v2.begin() + index;
            v2.erase(j);
        }
    }
}

int main() {
    const vector<int> a = {0, 5};
    vector<int> b = {1, 2, 3};
    process(a, b);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i];
    }
    return 0;
}