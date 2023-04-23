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

using namespace std;

class Date {
public:
    int y, m, d;
    
    Date(string tmp) {
        int index = 0;
        
        int num = 0;
        while (tmp[index] != '/') {
            if (tmp[index] >= '0' && tmp[index] <= '9') {
                num = num * 10 + tmp[index] - '0';
            }
            index++;
        }
        index++;
        
        this->y = num;
        
        num = 0;
        while (tmp[index] != '/') {
            if (tmp[index] >= '0' && tmp[index] <= '9') {
                num = num * 10 + tmp[index] - '0';
            }
            index++;
        }
        index++;
        
        this->m = num;
        
        num = 0;
        int len = tmp.length();
        while (index < len) {
            if (tmp[index] >= '0' && tmp[index] <= '9') {
                num = num * 10 + tmp[index] - '0';
            }
            index++;
            len = tmp.length();
        }
        
        this->d =  num;   
    }
    
    void print_date() const{
        cout << y << "/";
        
        if (m >= 10) {
            cout << m << "/";
        } else {
            cout << "0" << m << "/";
        }
        
        
        if (d >= 10) {
            cout << d << " ";
        } else {
            cout << "0" << d << " ";
        }
    }
    
    friend bool operator<(const Date &a, const Date &b) {
        if (a.y != b.y) return (a.y < b.y);
        if (a.m != b.m) return (a.m < b.m);
        return a.d < b.d;
    }
    
    friend bool operator ==(const Date &a, const Date &b) {
        return (a.y ==  b.y) && (a.m == b.m) && (a.d == b.d);
    }
};

int main()
{
    map <string, map<Date, int>> arr;
    map <string, map<Date, int>>::iterator j;
    
    set<Date> dates;
    set<Date>::iterator i;
    
    string name, date;
    int mark;
    
    while ((cin >> name) && (cin >> date) && (cin >> mark)) {
        Date t(date);
        arr[name][t] = mark;
        dates.insert(dates.end(), date);
    }
    
    cout << ". ";
    for (i = dates.begin(); i != dates.end(); i++) {
        (*i).print_date();
    }
    cout << endl;
    
    for (j = arr.begin(); j!= arr.end(); j++) {
        cout << j->first << " "; // name
   
        for (i = dates.begin(); i!=dates.end(); i++) { // run throught vector
            
            if (j->second.find(*i) != j->second.end()) {
                cout << (j->second)[*i] << " ";
            } else {
                cout << ". ";
            }
        }
        
        cout << endl;
    }
    
    cout << endl;
    
    return 0;
}