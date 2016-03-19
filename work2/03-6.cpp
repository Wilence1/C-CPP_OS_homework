#include <iostream>
using namespace std;
class B {
	int a, b;
public:
	B(int a, int b = 3) {
		this -> a = a;
		this -> b = b;
	};

	int get(){
		return a + b;
	}
	B& operator+= (B &a) {
		this -> a += a.a;
		this -> b += a.b;
		return *this;
	}

};