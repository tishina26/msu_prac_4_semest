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

class Figure {
    public:
        virtual bool equals(const Figure*) const = 0;
        virtual ~Figure() {};
};

class Rectangle:public Figure {
    private:
        int a, b;
    public:
        Rectangle(int a = 0, int b = 0): a(a), b(b) {};

        bool equals(const Figure *f) const {
            const Rectangle *tmp = dynamic_cast<const Rectangle*>(f);

            return (tmp && (a == tmp->a) && (b == tmp->b));
        }
};

class Triangle: public Figure {
    private:
        int a, b, c;
    public:
        Triangle(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {};

        bool equals(const Figure *f) const {
            const Triangle *tmp = dynamic_cast<const Triangle*>(f);
            
            return (tmp && (a == tmp->a) &&(b == tmp->b) && (c == tmp->c));
        }
};

int main() {
    Rectangle r1(10, 5), r2(10, 2), r3(10, 5), r4(5, 10);
    Triangle t1(1, 2, 3);
    Figure *f = &r1;

    assert(!f->equals(&r2));
    assert(f->equals(&r3));
    assert(!f->equals(&r4));
    assert(!f->equals(&t1));
    assert(!f->equals(nullptr));
}
