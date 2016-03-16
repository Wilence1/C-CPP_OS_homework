#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
namespace numbers {
    class complex_stack {
        complex* body = nullptr;
        int top, body_size;
    public:
        complex_stack(int x = 1)
        {
            body_size = x;
            top = 0;
            body = new complex[x];
        }
        complex_stack(const complex_stack &other);
        ~complex_stack()
        {
            delete []body;
        }
        size_t size() const
        {
            return top;
        }
        complex operator[] (size_t ind) const
        {
            return body[ind];
        }
        void swap(complex_stack &other)
        {
            std::swap(body_size, other.body_size);
            std::swap(top, other.top);
            std::swap(body, other.body);
        }
        complex_stack operator = (complex_stack other)
        {
            swap(other);
            return *this;
        }
        void push(const complex newval)
        {
            if (top == body_size) {
                complex * tmp = new complex[2 * body_size];
                memcpy(tmp, body, top * sizeof(*tmp));
                delete [] body;
                body = tmp;
                body_size = body_size * 2;
            }
            body[top++] = newval;
        }
        friend complex_stack operator << (const complex_stack& st, const complex newval)
        {
            complex_stack t(st);
            t.push(newval);
            return t;
        }
        complex_stack operator ~()const
        {
            complex_stack t(*this);
            t.top--;
            return t;
        }
        complex operator +() const
        {
            return body[top - 1];
        }
    };
    complex_stack::complex_stack(const complex_stack & other) 
    {
        body_size = other.body_size;
        top = other.top;
        body = new complex[body_size];
        memcpy(body, other.body, body_size * sizeof(*body));
    }
}