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

int main()
{
    string str;
    int mark;
    
    map<string, pair<int, int>> mp;
    
    while ((cin >> str) && (cin >> mark)) {
        if (mp.find(str) != mp.end()) {
            mp[str].first += mark;
            mp[str].second++;
        } else {
            mp[str].first = mark;
            mp[str].second = 1;
        }
    }
    
    map<string, pair<int, int>>::iterator i = mp.begin();
    
    while (i != mp.end()) {
        cout << i->first << " " << double(i->second.first) / double(i->second.second) << endl;
        i++;
    }
    
    return 0;
}