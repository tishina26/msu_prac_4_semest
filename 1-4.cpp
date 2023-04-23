#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

enum
{
    POINTS = 10
};

int main() {
    double a, sum = 0, summ = 0;
    int n = 0;

    cin.tie(nullptr);

    while ((cin >> a)) {
        sum += a;
        summ += a * a;
        n++;    
    }

    double d = sum / n;
    cout << fixed << showpoint << setprecision(10) << d << endl;
    cout << fixed << showpoint << setprecision(10) << sqrt(summ / n - d*d) << endl;

    return 0;
}