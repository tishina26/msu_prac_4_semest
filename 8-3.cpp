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

class S {
    public:
        bool exist = false;
        bool end = false;
        bool if_it_first;
        int a;
        
        S(bool if_it_first = true, bool exist = false) {
            this->if_it_first = if_it_first;
            this->exist = exist;
            if (!(cin >> a)) {
                // не прочли
                this->end = true;
                
                if (if_it_first == true) {
                    this->exist = false;
                } else {
                    throw 1;
                }
            } else {
                this->exist = true;
            }
        }
        
        
        S(const S& v) {
            a = v.a;
            end = v.end;
            exist = v.exist;
            
            try {
                S tmp(false, true);
                a += tmp.a;
            }
            catch(...) {
                end = true;
            }
        }
        
        explicit operator bool() const { 
            return end == false;
        }
        
        ~S() {
            if (exist && end) {
                cout <<a << endl;
            }
        }
};

void func(S v)
{
    if (v) {
        func(move(v));
    }
}

int main()
{
    func(S());
}