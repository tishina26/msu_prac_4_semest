#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    int sum_a = 0, sum_b = 0;
    
    while (a > 0) {
        sum_a += a % 2;
        a /= 2;
    }
    while (b > 0) {
        sum_b += b % 2;
        b /= 2;
    }
    
    return sum_a < sum_b;
}

int main()
{
    vector<int> v;
    
    int c;
    while (cin >> c) {
        v.push_back(c);
    }
    
    stable_sort(v.begin(), v.end(), comp);
    
    int s = v.size();
    for (int i = 0; i < s; i++) {
        cout << v[i] << endl;
    }
    
    return 0;
}