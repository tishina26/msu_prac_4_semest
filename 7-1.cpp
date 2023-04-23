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

class Figure {
    public:
        virtual double get_square() const = 0;
        virtual ~Figure() {};
};