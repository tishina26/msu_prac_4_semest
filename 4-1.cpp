#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

void process(const vector<uint64_t>& a, vector<uint64_t>& b, int step) {
	if (b.size() == 0) {
		return;
	}

	vector<uint64_t> :: const_iterator i = a.begin();
	vector<uint64_t> :: iterator j = b.end() - 1;

	for (; i < a.end(); i += step) {
		if (j < b.begin()) {
			return;
		}
		*j += *i;
		j--;
	}
	return;
}