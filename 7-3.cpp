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

using namespace std;

class FigureFactory {
    public:
        static FigureFactory &factory_instance() {
            static FigureFactory instance;
            return instance;
        }

        static Figure *get_object(string str) {
            stringstream str_tmp;
            string figure, a, b;

            str_tmp << str;
            str_tmp >> figure;

            if (figure == "R") {
                str_tmp >> a >> b;
                return Rectangle::make(a + " " + b);
            } else if (figure == "S") {
                str_tmp >> a;
                return Square::make(a);
            } else if (figure == "C") {
                str_tmp >> a;
                return Circle::make(a);
            } else {
                return nullptr;
            }
        }  
};

bool comparator(const Figure* x, const Figure* y) {
    return ((x->get_square()) < (y->get_square()));
}

int main() {
    vector<Figure*> arr;
    vector<Figure*>::iterator i = arr.begin();
    string str;

    while (getline(cin, str)) {
        Figure *tmp = FigureFactory::factory_instance().get_object(str);
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), comparator);

    for (i = arr.begin(); i != arr.end(); i++) {
        cout << (*i)->to_string() << endl;
        delete (*i);
    }

    return 0;
}