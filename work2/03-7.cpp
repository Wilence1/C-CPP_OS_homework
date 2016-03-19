#include <iostream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

class C
{
    double x;
    double y;
public:
    C(double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    friend C operator& (const C & a)
    {
        return a;
    }
    friend double operator~ (const C & a)
    {
        return a.x;
    }
    friend C operator++ (const C & a)
    {
        return a;
    }
    friend double operator+ (int x, const C & a)
    {
        return a.x + x;
    }
    friend double operator* (const C & a, const C * b)
    {
        return a.x;
    }
};