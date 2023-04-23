#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cmath>

using std::string;
using std::setprecision;
using std::ostringstream;


namespace numbers {
	class complex {
		double RE, IM;
	public:
		complex(double x = 0.0, double y = 0.0):RE(x),IM(y) {}

		explicit complex (string str) {
			int i = 1;
			while (str[i] != ',') i++;

			this->RE = stod(str.substr(1, i));
			
			this->IM = stod(str.substr(i+1, str.length()-i-1));
		}

		double re() const{
			return RE;
		}
		double im() const{
			return IM;
		}

		double abs() const{
			return sqrt(RE*RE+IM*IM);
		}
		double abs2() const{
			return RE*RE+IM*IM;
		}

		string to_string() const{
			ostringstream s;
			s << "(" << setprecision(10) << RE << "," << setprecision(10) << IM << ")";
			return s.str();
		}


		complex operator += (const complex & x) {
			return complex(RE+=x.RE, IM+=x.IM);
		}
		complex operator -= (const complex & x) {
			return complex(RE-=x.RE, IM-=x.IM);
		}
		complex operator *= (const complex & x) {
			double tmp = RE*x.RE-IM*x.IM;
			IM = IM*x.RE+RE*x.IM;
			RE = tmp;
			return complex(RE, IM);
		}
		complex operator /= (const complex & x) {
			double tmp = RE * x.RE + IM * x.IM;
			tmp /= x.abs2();
			IM = IM * x.RE - RE * x.IM;
			IM /= x.abs2();
			RE = tmp;
			return complex(RE, IM);
		}

		friend complex operator + (const complex & a, const complex & b) {
			complex tmp(a);
			tmp += b;
			return tmp;
		}
		friend complex operator - (const complex & a, const complex & b) {
			complex tmp(a);
			tmp -= b;
			return tmp;
		}
		friend complex operator * (const complex & a, const complex & b) {
			complex tmp(a);
			tmp *= b;
			return tmp;
		}
		friend complex operator / (const complex & a, const complex & b) {
			complex tmp(a);
			tmp /= b;
			return tmp;
		}

		complex operator-() const{
			return complex(-RE, -IM);
		}
		complex operator~() const{
			return complex(RE, -IM);
		}
	};
};

using namespace numbers;
using namespace std;

int main() {
	complex a(1, 2), b(-2, 7);
	string s = "( 1.9,-5)";
	complex c = complex(s);
	cout << c.re() << ' ' << c.im()<<endl;
	cout << a.to_string();
}