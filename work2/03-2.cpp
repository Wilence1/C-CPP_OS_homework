#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void process(const vector <int> v, list <int> & lst) 
{
    vector <int> vi = v;
    
    sort(vi.begin(), vi.end());
    
    auto tmp = unique(vi.begin(), vi.end());
    vi.erase(tmp, vi.end());

    int cur = 1;
    
    int val = lst.size();
    
    auto it = lst.begin();
    auto ii = vi.begin();
    
    while(ii != vi.end() && *ii < 1) {
        ii++;
    }

    while(ii != vi.end() && it != lst.end() && *ii <= val ) {
        if(*ii > cur) {
            it++;
        } else {
            ii++;
            it =lst.erase(it);
        }
        cur++;  
    }
}