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
typename T::value_type process(T cont) {
    typename T::value_type x;
    typename T::const_iterator it = cont.end();
    
    if (cont.size() == 0) {
        return typename T::value_type();
    }
    
    it--;
    x = *it;

    if (cont.size() >= 3) {
        it--; it--;
        x += *it;
        
        if (cont.size() >=  5) {
            it--; it--;
            x += *it;
        }
    }
    
    return x;
}