#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
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
        auto q1 = (a.get_re()*b.get_re()+a.get_im()*b.get_im())/b.abs2();
        auto q2 = (a.get_im()*b.get_re()-a.get_re()*b.get_im())/b.abs2();
        complex t(q1, q2);
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
    
    class complex_stack {
    public:
        complex* body = nullptr;
        int top, body_size;
        
        complex_stack(int x = 1) { // конструктор по умолчанию
            body_size = x;
            top = 0;
            body = new complex[x];
        }
        
        complex_stack(const complex_stack &other); // конструктор копирования
        
        ~complex_stack() { // деструктор
            delete []body;
        }
        size_t size() const {
            return top;
        }
        
        complex operator[] (size_t ind) const {
            return body[ind];
        }
        
        void swap(complex_stack &other) {
            std::swap(body_size, other.body_size);
            std::swap(top, other.top);
            std::swap(body, other.body);
        }
        
        complex_stack operator = (complex_stack other) {
            swap(other);
            return *this;
        }
        
        void push(const complex newval) {
            if (top == body_size) {
                complex * tmp = new complex[2 * body_size];
                memcpy(tmp, body, top * sizeof(*tmp));
                delete [] body;
                body = tmp;
                body_size = body_size * 2;
            }
            body[top++] = newval;
        }
        friend complex_stack operator << (const complex_stack& st, const complex newval) {
            complex_stack t(st);
            t.push(newval);
            return t;
        }
        complex_stack operator ~() {
            complex_stack t(*this);
            t.top--;
            return t;
        }
        
        complex operator +() const {
            return body[top - 1];
        }
    };
    
    complex_stack::complex_stack(const complex_stack & other) {
        body_size = other.body_size;
        top = other.top;
        body = new complex[body_size];
        memcpy(body, other.body, body_size * sizeof(*body));
    }
    
    
    complex eval(char **args, const complex &z) {
        complex_stack a;
        for(int i = 0; args[i] != NULL; i++){
            
            if(args[i][0] == 'z') {
                a = a << z;
            }
            if(args[i][0] == '(') {
                complex tmp = complex(args[i]);
                a = a << tmp;
            }
            
            if(args[i][0] == '+') {
                complex arg = +a;
                a = ~a;
                complex arg2 = +a;
                a = ~a;
                a = a << (arg + arg2);
            }
            if(args[i][0] == '-') {
                complex arg = +a;
                a = ~a;
                complex arg2 = +a;
                a = ~a;
                a = a << (arg2 - arg);
                
            }
            if(args[i][0] == '*') {
                complex arg = +a;
                a = ~a;
                complex arg2 = +a;
                a = ~a;
                a = a << (arg * arg2);
            }
            if(args[i][0] == '/') {
                complex arg = +a;
                a = ~a;
                complex arg2 = +a;
                a = ~a;
                a = a << (arg2 / arg);
            }
            if(args[i][0] == '!') {
                a = a << (+a);
            }
            if(args[i][0] == ';') {
                a = ~a;
            }
            if(args[i][0] == '#') {
                complex t = +a;
                a = ~a;
                t = -t;
                a = a << t;
            }
            if(args[i][0] == '~') {
                complex t = +a;
                a = ~a;
                t = ~t;
                a = a << t;
            }
        }
        return +a;
    }
}