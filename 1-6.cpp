#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

double eps = 0.000001;

class Point {
    double x, y;
    int if_exists;

    public:
        Point(double x = 0,double y = 0,int if_exists = 0) {
            this->if_exists = if_exists;
            this->x = x;
            this->y = y;
        }

        double getx() const{
            return x;
        }
        double gety() const{
            return y;
        }
        int getex() const{
            return if_exists;
        }
};

class Direct{
    double a, b, c;
    public:
        Direct(const Point & p1, const Point & p2) {
            // ay1 + bx1 + c = 0
            // ay2 + bx2 + c = 0
            double x1=p1.getx(), y1=p1.gety();
            double x2=p2.getx(), y2=p2.gety();

            if (abs(x1 - x2) <= eps) {
                this->a = 0;
                this->b = 1;
                this->c = -x1;
            } else {
                this->a = 1;
                this->b = (y2-y1)/(x1-x2);
                this->c = -(this->b * x2 + y2);
            }
        }

        double geta() const{
            return a;
        }
        double getb() const{
            return b;
        }
        double getc() const{
            return c;
        }
};

Point intersection(const Direct & v1, const Direct & v2) {
    double x = 0, y = 0;
    int if_exists = 0;
    double a1 = v1.geta(), b1 = v1.getb(), c1 = v1.getc();
    double a2 = v2.geta(), b2 = v2.getb(), c2 = v2.getc();
    
    if (abs(a1-a1) < eps && abs(b1-b2) < eps && abs(c1 - c2) < eps) {
        if_exists = 2;
    } else if (!(abs(a1*b2-a2*b1) < eps)) {
        // a1y+b1x+c1=0
        // a2y+b2x+c2=0
        // a1b2y+b1b2x+c1b2=0
        // a2b1y+b2b1x+c2b1=0
        // y = (c2b1-c1b2)/(a1b2-a2b1)
        y = (c2*b1-c1*b2)/(a1*b2-a2*b1);
        if (!(abs(b1) < eps)) {
            x = -(a1*y+c1)/b1;
        }
        if (!(abs(b2) < eps)) {
            x = -(a2*y+c2)/b2;
        }
        if_exists = 1;
    }

    Point p(x,y,if_exists);
    
    return p;
}

void print_direct(const Direct & v) {
    double a = v.geta(), b = v.getb(), c = v.getc();
    cout<<"line"<<endl;
    cout << fixed << showpoint << setprecision(10) << a << endl;
    cout << fixed << showpoint << setprecision(10) << b << endl;
    cout << fixed << showpoint << setprecision(10) << c << endl;
}

int main() {
    double x, y;
    int if_exists = 1;
    cin >> x; cin >> y;
    Point p1(x,y,if_exists);
    cin >> x; cin >> y;
    Point p2(x,y,if_exists);
    cin >> x; cin >> y;
    Point pp1(x,y,if_exists);
    cin >> x; cin >> y;
    Point pp2(x,y,if_exists);

    Direct d1(p1,p2);
    Direct d2(pp1,pp2);

    Point ans = intersection(d1,d2);
    x=ans.getx(), y=ans.gety();
    if_exists=ans.getex();
    
    if (if_exists != 1) {
        cout << int(if_exists);
    } else {
        cout << int(if_exists) << endl;
        cout << fixed << showpoint << setprecision(10) << x << endl;
        cout << fixed << showpoint << setprecision(10) << y << endl;
    }

    return 0;
}