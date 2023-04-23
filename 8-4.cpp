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
#include <complex>

using namespace std;

namespace Equations {
    template<class T>
    pair<bool, vector<T>> quadratic(array<T, 3> &v) {
        T c = v[0], b = v[1], a = v[2], zero(0,0);
        vector<T> root;
        bool flag = true;
        
        if (a == zero && b != zero) {
            root.push_back(-c/b);
        } else if (b == zero && a != zero) {
            T x = sqrt(-c/a);
            root.push_back(x);
            root.push_back(-x);
        } else if (a == zero && b == zero) {
            if (c == zero) flag = false; //  бесконечно много корней
        } else {
            T four(4, 0), two(2, 0);
            T discr = sqrt(b*b-four*a*c);
            root.push_back(((-b) + discr)/(two*a));
            root.push_back(((-b) - discr)/(two*a));
        }
        
        pair<bool, vector<T>> ans = make_pair(flag, root);
        return ans;
    }
};

/*
int main()
{
    using namespace std::complex_literals;

    std::array v1{ 5.0-1i, -3.0+2i,1.0-0i };

    auto [res, v2] = Equations::quadratic(v1);
    std::cout << res;
    if (res) {
        auto it = (v2).begin();
        for (;it != (v2).end(); it++) {
            cout << *it;
        }
    }

}
*/
/*
int main()
{
    std::array<std::complex<double>, 3> v1{
        std::complex<double>(5,0),
        std::complex<double>(6, 0),
        std::complex<double>(5, 0)
    };

    auto res = Equations::quadratic(v1);
    if (res.first) {
        auto it = (res.second).begin();
        for (;it != (res.second).end(); it++) {
            cout << *it;
        }
    }
}
*/