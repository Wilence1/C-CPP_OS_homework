#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	double a;
	double sum = 0;
	int k = 0;
	double ans = 0;
	vector <double> data;
	while(cin >> a) {
		k++;
		sum += a;
		data.push_back(a);
	}
	for(int i = 0; i < (int) data.size(); i++) {
		ans += (sum/k - data[i]) * (sum/k - data[i]);
	}
	cout << setprecision(10) << sum/k << endl; 

	cout << setprecision(10) << sqrt(ans/k) << endl; 

}