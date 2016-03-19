#include <iostream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    while(cin >> s) {
        int val = s.length();
        for(int i = 0; i < val; i++){
            s.resize(val - i);
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            if(!s.compare(tmp)) {
                cout << s << endl;
                break;
            }
        }
    }
}