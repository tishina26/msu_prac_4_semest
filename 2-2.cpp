#include <iostream>

class C {
	static const char c;
	public:
	    static void f()
	    {
	        return;
	    }
};

const char C::c = '+';
int main()
{
    C ob;
    C::f();
    return 0;
}
