#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>

using std::string;
using std::setprecision;
using std::ostringstream;

namespace numbers {
    class complex_stack {
        complex* ptr; // указатель на массив
        size_t used; // готов к записи
        size_t alloc; // количество элементов выделенных
    public:
        complex_stack(size_t a = 0, size_t b = 0):used(a), alloc(b) {
            ptr = static_cast<complex*>(::operator new(alloc * sizeof(complex)));
        }

        // копирование
        complex_stack(const complex_stack &v):used(v.used),alloc(v.alloc) {
            ptr = static_cast<complex*>(::operator new(alloc * sizeof(complex)));
            for(size_t i = 0; i < used; i++) {
                new (ptr+i) complex (v.ptr[i]); // принудительно по адресу i размещаем
            }
        }

        complex_stack(complex_stack &&v)  {
            alloc = v.alloc;
            ptr = v.ptr;
            used = v.used;
            v.ptr = nullptr;
        }

        ~complex_stack() {
            for(size_t i = 0; i < used; i++) {
                ptr[i].~complex();
            }
            alloc = 0; used = 0;
            ::operator delete(ptr);
        }

        complex& operator[] (size_t i) const {
            return ptr[i];
        }

        size_t size() const {
            return used;
        }

        complex_stack& operator=(const complex_stack &v) {
            if (&v == this) {
                return *this;
            }

            for (size_t i = 0; i < used; i++) {
                ptr[i].~complex();
            }
            ::operator delete(ptr);

            alloc = v.alloc; used = v.used;

            ptr = static_cast<complex*>(::operator new(alloc * sizeof(complex)));
            for(size_t i = 0; i < used; i++) {
                new (ptr+i) complex (v.ptr[i]); // принудительно по адресу i размещаем
            }

            return *this;
        }

        complex operator+() const {
            return ptr[used - 1];
        }

        complex_stack operator~() const {
            complex_stack tmp(used - 1, alloc);
            for (size_t i = 0; i < used - 1; i++) {
                new (tmp.ptr + i) complex (ptr[i]);
            }

            return tmp;
        }

        friend complex_stack operator<<(const complex_stack v, const complex x) {
            size_t n = v.alloc;

            n += (v.used == 0) ? 1 : 0;
            n *= (v.used == v.alloc) ? 2 : 1;

            complex_stack tmp(v.used + 1, n);

            for (size_t i = 0; i < v.used; i++) {
                new (tmp.ptr + i) complex (v[i]);
            }

            new (tmp.ptr + v.used) complex (x);

            return tmp;
        }
    };
};

using numbers::complex;
using numbers::complex_stack;

int main() {
    const complex_stack s1;

    complex c1 = complex(1, 2);
    complex c2 = complex(4, 8);

    cout << s1.size();
    const complex_stack s2 = s1 << c1;
    cout << s2.size();
}