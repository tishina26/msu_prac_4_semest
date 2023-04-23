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

unsigned long long NUM = 4294967161;

int main()
{
    map <pair<unsigned int, unsigned int>, unsigned long long> mp;
    map <pair<unsigned int, unsigned int>, unsigned long long> ans;
    map <unsigned int, vector<unsigned int>> use; // для столбца храню вектор строк
    vector<unsigned int>::iterator iter;
    unsigned int i, j, k;
    unsigned long long n;
    
    while ((cin >> i) && (cin >> j) &&(cin >> n) && !(i == 0 && j == 0 && n == NUM)) {
        mp[make_pair(i, j)] = n;
        use[j].push_back(i);
    }
    
    while ((cin >> i) && (cin >> j) &&(cin >> n)) {
        for (iter = use[i].begin(); iter != use[i].end(); iter++) {
            k = *iter;

            if (ans.find(make_pair(k, j)) == ans.end()) {
                ans[make_pair(k, j)] = 0;
            }
            
            ans[make_pair(k, j)] = (ans[make_pair(k, j)] + (n * mp[make_pair(k, i)]) % NUM) % NUM;
        }
    }
    
    map <pair<unsigned int, unsigned int>, unsigned long long>::iterator it = ans.begin();
    
    while (it != ans.end()) {
        if (it->second != 0) {
            cout << it->first.first << " " << it->first.second << " " << it->second << endl;
        }

        it++;
    }
    
    return 0;
}