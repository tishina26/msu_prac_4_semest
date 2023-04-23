#include <iostream>
#include <cstring>

using namespace std;


class BinaryNumber
{
	string s;
public:
    BinaryNumber(const string &s) {
    	this->s = s;
    }

    operator string () const {
    	return s;
    }

    const BinaryNumber &operator++() {
    	int i = s.length() - 1;
    	while (i >0 && s[i] != '0') {
    		s[i] = '0';
    		i--;
    	}
    	if (s[i] == '0') {
    		s[i] = '1';
    	} else {
    		s[i] = '0';
    		s = '1' + s;
    	}

    	return *this;
    }
};