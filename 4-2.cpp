#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

void process(vector<int64_t>& a, int64_t minimum) {
	if (a.size() == 0) {
		return;
	}

	vector<int64_t> :: iterator i = a.end() - 1;
	int64_t cnt = 0;

	for (; i >= a.begin(); i--) {
		if (*i >= minimum) {
			cnt++;
		}
	}

	a.reserve(a.size() + cnt); // realloc

	for (i = a.end() - 1; i >= a.begin(); i--) {
		if (*i >= minimum) {
			a.push_back(*i);
		}
	}
	return;
}