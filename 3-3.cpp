#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <functional>
#include <map>

using std::string;
using std::setprecision;
using std::ostringstream;

using std::vector;
using std::map;
using std::function;

namespace numbers {
    complex eval(const vector<string> &args, const complex &z) {
        complex_stack v;
        map<string, function<void()>> mp {
            {"+", [&v]() {
                // last 2 numbers
                complex num_1 = +v;
                v = ~v;
                complex num_2 = +v;
                v = ~v;
                num_2 += num_1;

                v = v << num_2;
            }},
            {"-", [&v]() {
                // last 2 numbers
                complex num_1 = +v;
                v = ~v;
                complex num_2 = +v;
                v = ~v;
                num_2 -= num_1;

                v = v << num_2;
            }},
            {"*", [&v]() {
                // last 2 numbers
                complex num_1 = +v;
                v = ~v;
                complex num_2 = +v;
                v = ~v;
                num_2 *= num_1;

                v = v << num_2;
            }},
            {"/", [&v]() {
                // last 2 numbers
                complex num_1 = +v;
                v = ~v;
                complex num_2 = +v;
                v = ~v;
                num_2 /= num_1;

                v = v << num_2;
            }},
            {"!", [&v]() {
                complex tmp = +v;
                v = v << tmp;
            }},
            {";", [&v]() {
                v = ~v;
            }},
            {"~", [&v]() {
                complex tmp = +v;
                v = ~v;
                tmp = ~tmp;
                v = v << tmp;
            }},
            {"#", [&v]() {
                complex tmp = +v;
                v = ~v;
                tmp = -tmp;
                v = v << tmp;
            }},
            {"z", [&v, &z]() {
                v = v << z;
            }}
        };

        size_t size = args.size();

        for (size_t i = 0; i < size; i++) {
            string x = args[i];
            if ((x == "+") || (x == "-") || (x == "*") || (x == "/") || 
                (x == "!") || (x == ";") || (x == "~") || (x == "#") ||
                (x == "z")){
            
                mp[args[i]]();
            } else {
                complex x(args[i]);
                v = v << x;
            }
        }

        complex a = +v;

        return a;
    }
};
