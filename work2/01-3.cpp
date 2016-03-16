#include <iostream>
using namespace std;
class Sum {
public:
	int x, y;
public:
	Sum(int x, int y){
		this->x = x;
		this->y = y;
	}
public:
	int get() {
		return this->x + this->y;
	}
};