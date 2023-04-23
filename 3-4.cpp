#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <functional>
#include <map>

#include <cmc_complex.h>
#include <cmc_complex_stack.h>
#include <cmc_complex_eval.h>

using std::string;
using std::setprecision;
using std::ostringstream;

using std::vector;
using std::map;
using std::function;


using numbers::complex;
using numbers::complex_stack;
using numbers::eval;
using std::cout;
using std::endl;
using std::stod;
using std::stoi;

int main(int argc, char** argv) {
    complex c(argv[1]);
    double r = stod(argv[2]);
    int n = stoi(argv[3]);

    vector<string> args;
    for (int i = 4; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // метод прямоугольников
    double a, b, m, d = 2 * M_PI / n; // длина отрезка разбиения
    complex ans(0, 0), len(d, 0);

    for (int i = 0; i < n; i++) {
        a = d * i;
        b = a + d;

        m = (a + b) / 2;

        complex u(r * cos(m) + c.re(), r * sin(m) + c.im());
        complex du(-r * sin(m), r * cos(m));

        ans += (eval(args, u) * len * du);
    }

    cout << ans.to_string() << endl;

    return 0;
}