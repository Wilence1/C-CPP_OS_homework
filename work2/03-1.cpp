#include <iostream>
#include <vector>
#include <list>
using namespace std;
void process(const vector <int> vi, list <int> & li, int x) 
{
	int val = li.size();
	int d = 0;
	auto ii = li.begin();
	for(auto it = vi.begin(); it < vi.end()  && d < val; it+= x) {
			*ii = *it;
			ii++;
			d++;
	}
	for(auto ii = li.rbegin(); ii != li.rend(); ii++) {
		cout << *ii << endl;
	}
}