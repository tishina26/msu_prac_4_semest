#include <iostream>

using namespace std;

int main() {
	cin >> noskipws;
	cin.tie(nullptr);

	char c, a;
	int n = 1;

	a = cin.get();
	if (a == EOF) {
		return 0;
	}

    while (cin >> c) {
    	if (c == a) {
	        n++;
	    } else {
	    	if ((n <= 4) && (a != '#')) {
	    		for (int i = 0; i < n; i++) {
	    			cout << a;
	    		}

	    		n = 1;
	    	} else {
				cout << '#' << a << hex << n << '#';
				n = 1;
	    	}
	    }

        a = c;
    }
    
	if ((n <= 4) && (a != '#')) {
		for (int i = 0; i < n; i++) {
			cout << a;
		}

		n = 1;
	} else {
		cout << '#' << a << hex << n << '#';
		n = 1;
	}

	return 0;
}  