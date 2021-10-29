#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

string s;

int main() {
    cin >> s;
    if(s.length() == 6) {
        for(int i=0; i<=3; i++) cout << s[i];
        cout << '-' ;
        cout << s[4] << s[5] << endl;
    } else {
        if((s[0] == '2' && s[1] < '2') || s[0] < '2') {
            cout << "20" << s[0] << s[1] << '-' << s[2] << s[3] << endl;
        } else {
            cout << "19" << s[0] << s[1] << '-' << s[2] << s[3] << endl;
        }
    }
    return 0;
}