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

template<typename T>
void selection_sort(T begin, T end) {
    if (begin == end) {
        return;
    }
    
    T i = begin, j, min = begin;
    
    for (; i != end; i++) {
        min = i;
        
        for (j = i + 1; j != end; j++) {
            if (*j < *min) {
                min = j;
            }
        }
        
        iter_swap(min, i);
    }
}

template<typename T>
void selection_sort(T begin, T end, function<bool(typename iterator_traits<T>::value_type&, typename iterator_traits<T>::value_type&)> f) {
    if (begin == end) {
        return;
    }
    
    T i = begin, j, min = begin;
    
    for (; i != end; i++) {
        min = i;

        for (j = i + 1; j != end; j++) {
            if (f(*j, *min)) {
                min = j;
            }   
        }
        
        iter_swap(min, i);
    }
}


bool f(int& a, int&  b) {
    return a > b;
}
int main(int argc, char** argv) {
    vector<int> ar = {1, 3, 2};
    vector<int> ar2 = {1, 3, 2};
    //int ar[] = {};
    //selection_sort(begin(ar), end(ar));
    selection_sort(ar.begin(), ar.end());
    sort(ar2.begin(), ar2.end());

    for (auto i = ar.begin(); i != ar.end(); i++) {
    //  for (auto i = begin(ar); i != end(ar); i++) {
        cout << *i << " ";
    }
    for (auto i = ar2.begin(); i != ar2.end(); i++) {
    //  for (auto i = begin(ar); i != end(ar); i++) {
        cout << *i << " ";
    }

    return 0;
}