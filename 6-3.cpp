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

template<class T>
void myapply(T begin, T end, function<void(typename iterator_traits<T>::value_type&)> f) {
    for (auto i = begin; i != end; i++) {
        f(*i);
    }
}


template<class T>
vector<reference_wrapper<typename iterator_traits<T>::value_type>>
myfilter2(T begin, T end, function<bool(typename iterator_traits<T>::value_type&)> f) {
    vector<reference_wrapper<typename iterator_traits<T>::value_type>> arr;
    
    for (auto i = begin; i != end; i++) {
        if (f(*i)) {
            arr.push_back(*i);
        }
    }

    return arr;
}

bool f(int& a) {
    return a < 0;
}
int main(int argc, char** argv) {
     //vector<int> ar = {1, 2, 3, -8};
     int ar[] = {1,2,3,-8};
     vector<reference_wrapper<int>> ans = myfilter2(begin(ar), end(ar), f);

     for (auto i = ans.begin(); i != ans.end(); i++) {
         cout << *i << " ";
     }

     return 0;
 }
 