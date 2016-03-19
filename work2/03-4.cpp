#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
using namespace std;
struct average 
{
public:
    double sum;
    average() 
    {
        sum = 0;
    }
    void operator()(double i)
    {
        sum += i;
    }   
    double get()
    {
        return sum;
    }
};
int main() 
{
    double x;
    vector <double> data;
    int val = 0;
    while(cin >> x) 
    {
        data.push_back(x);
        val++;
    }
    int less = (int) (0.1 * val);
    sort(data.begin() + less, data.end() - less);
    
    int less1 = (int) (0.1 * (val - 2 * less));

    average z;
    cout << endl;
    z = for_each(data.begin() + less + less1, data.end() - less - less1, z);
    cout << fixed << setprecision(10) << z.get() / (data.size() - 2 * less - 2 * less1);
}