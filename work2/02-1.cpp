#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

namespace numbers {
	class complex {
		double re, im;
	public:
		complex(double r = 0.0, double i = 0.0): re(r), im(i) {	
		}
		explicit complex(const char * s) 
		{
			sscanf(s, "(%lf,%lf)", &re, &im);
		}
		double get_re() const
		{
			return re;
		}
		double get_im() const
		{
			return im;
		}
		double abs2() const
		{
			return im * im + re * re;
		}
		double abs() const
		{
			return sqrt(im * im + re * re);
		}
		void to_string(char* buf, size_t size)  const 
		{
			snprintf(buf, size, "(%.10g,%.10g)", re, im);
		}
		friend complex operator+ (const complex &a, const complex &b);
		friend complex operator- (const complex &a, const complex &b);
		friend complex operator* (const complex &a, const complex &b);
		friend complex operator/ (const complex &a, const complex &b);
		friend complex operator~ (const complex &a);
		friend complex operator- (const complex &a);
	};
	complex operator+ (const complex &a, const complex &b)
	{
		complex t(b.get_re() + a.get_re(), b.get_im()  + a.get_im());
		return t;
	}
	complex operator- (const complex &a, const complex &b)
	{
		complex t(-b.get_re() + a.get_re(), -b.get_im()  + a.get_im());
		return t;
	}
	complex operator* (const complex &a, const complex &b)
	{
		complex t(b.get_re() * a.get_re() - b.get_im() * a.get_im(), b.get_im() * a.get_re() + b.get_re() * a.get_im());
		return t;
	}
	complex operator/ (const complex &a, const complex &b)
	{
		complex t((a.get_re() * b.get_re()  + a.get_im() * b.get_im())/b.abs2(), (a.get_im() * b.get_re() - a.get_re() * b.get_im())/b.abs2());
		return t;
	}
	complex operator~ (const complex &a) {
			complex t(a.get_re(), -a.get_im());
			return t;
	}
	complex operator- (const complex &a) {
			complex t(-a.get_re(), -a.get_im());
			return t;
	}
}