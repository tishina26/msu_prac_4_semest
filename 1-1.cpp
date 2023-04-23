#include <iostream>
#include <cstring>

using namespace std;

class Sum {
	int a, b;
	int sum;
	public:
		Sum(int x = 0,int y = 0) {
			a = x; b = y;
			sum = a + b;
		}

		Sum(const Sum & v, int & x) {
			a = v.sum;
			b = x;
			sum = a + b;
		}

		Sum(const Sum & v) {
			a = v.a; b = v.b;
			sum = v.sum;
		}


		int get() const{
			return sum;
		}
};

int main() {
	int a = 0, b = 7, c = 9;

	cout << Sum(a, b).get()<<endl;
	cout << Sum(Sum(a, b), c).get()<<endl;

	return 0;
}