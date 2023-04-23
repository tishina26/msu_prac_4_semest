#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <vector>
#include <functional>
#include <map>

using namespace std;

unsigned long long NUM = 4294967161;

int main()
{
    map <pair<unsigned int, unsigned int>, unsigned long long> mp;
    unsigned int i, j;
    unsigned long long n;

    while ((cin >> i) && (cin >> j) &&(cin >> n) && !(i == 0 && j == 0 && n == NUM)) {
        mp[make_pair(i, j)] = n;
    }

    while ((cin >> i) && (cin >> j) &&(cin >> n)) {
        if (mp.find(make_pair(i, j)) == mp.end()) {
            mp[make_pair(i, j)] = n % NUM;          
        } else {
            mp[make_pair(i, j)] = (mp[make_pair(i, j)] + (n % NUM)) % NUM;
        }
    }
    
    map <pair<unsigned int, unsigned int>, unsigned long long>::iterator it = mp.begin();
    
    while (it != mp.end()) {
        if (it->second != 0) {
            cout << it->first.first << " " << it->first.second << " " << it->second << endl;
        }
        
        it++;
    }
    
    
    return 0;
}