/* 
Класс Result хранит вывод функции из условия, класс Exit нужен для избежания неявного return
Функция f() реализует функцию из условия, делает throw Result(), внутри main есть соответствующий catch, где выводится поле класса Result
catch, не соответствующий классу Result, пустой   
*/

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

// хранит результат функции, описанной в условии 
class Result {
    public:
        long long a;
        Result(long long a) {
            this->a = a;
        }
};

// чтобы избежать неявного return
class Exit {};

// реализация функции из условия и передача результата в Result
void f(long long a, long long b, int k) {
    if (k == 0) {
        throw Result(a + b);
    } else if (k > 0 && b == 1) {
        throw Result(a);
    } else if (k > 0 && b > 1) {
        // нельзя делать так, как написано ниже, т к f() ничего не возвращает, поэтому вызовем отдельно от внутренней функции
        //f(a, f(a, b-1, k), k-1);
        try {
            f(a, b-1, k);
        }
        catch (Result &res) {
            f(a, res.a, k-1);
        }
    }
    throw Exit();
}

int main() {
    long long a, b;
    int k;
    
    while (cin >> a >> b >> k){
        try {
            f(a, b, k);
        }
        catch(Result &res) {
            cout << res.a << endl;
        }
        catch(...) {}
    }
    
    return 0;
}