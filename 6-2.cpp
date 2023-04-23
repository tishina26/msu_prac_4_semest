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

using namespace std;

template <class T>
T myfilter(T cont, function <bool(typename T::value_type)> predicat) {
    typename T::const_iterator it = cont.begin();
    T ans;
    
    for (; it != cont.end(); it++) {
        if (predicat(*it)) {
            ans.insert(ans.end(), *it);
        }
    }
    
    return ans;
}