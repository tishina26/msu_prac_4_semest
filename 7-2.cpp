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

/*
class Figure {
    public:
        virtual double get_square() const = 0;
        virtual ~Figure() {};
};
*/
 
class Rectangle:public Figure {
    private:
        double a, b;
    public:
        static Rectangle *make(const string &str) {
            Rectangle *tmp = new Rectangle;

            stringstream str_tmp;
            str_tmp << str;
            
            str_tmp >> (tmp->a) >> (tmp->b);

            return tmp;
        }

        double get_square() const {
            return a * b;
        }
};

class Square:public Figure {
    private:
        double a;
    public:
        static Square *make(const string &str) {
            Square *tmp = new Square;

            stringstream str_tmp;
            str_tmp << str;
            
            str_tmp >> (tmp->a);

            return tmp;
        }

        double get_square() const {
            return a * a;
        }
};

class Circle:public Figure {
    private:
        double r;
    public:
        static Circle *make(const string &str) {
            Circle *tmp = new Circle;

            stringstream str_tmp;
            str_tmp << str;

            str_tmp >> (tmp->r);

            return tmp;
        }

        double get_square() const {
            return r * r * M_PI;
        }
};

int main() {
    Square *tmp_2 = Square::make("6");
    cout << tmp_2->get_square();
    return 0;   
}
