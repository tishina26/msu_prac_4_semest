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

template<typename A>
void print_arr(A a1, A a2) {
    A it = a1;
    for (; it != a2; it++) {
      cout << *it << " ";
    }
    cout << endl;
}

template<typename A, typename B>
B myremove(A a1, A a2, B b1, B b2) {
    if ((a1 == a2) || (b1 == b2)) {
        return b2;
    }
    
    A if_found;
    int i = 0;
    B real_index = b1, write = b1, copy_end = b2;
    
    while ((real_index != b2) && (write != b2)) {
        if_found = find(a1, a2, i);
        if (if_found == a2) {
            iter_swap(write, real_index);
            real_index++;
        } else { //del
            copy_end--;
        }
        write++;
        i++;
    }
    
    return copy_end;
}


int main(int argc, char const **argv) {
    vector<int> b = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> a = {};

    auto tmp = myremove(a.begin(), a.end(), b.begin(), b.end());
    print_arr(b.begin(), tmp);

    return 0;
}
