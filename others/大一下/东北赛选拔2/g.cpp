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

int t;
int a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        bool st ;
        if(a < 0) st = 0;
        else st = 1;

        if(a == 0) {
            cout << 1 << endl;
            cout << b << endl;
            continue;
        }
        int dt = a*a+4*a*b;
        int r = int(sqrt(dt));
        if(r == 0) {
            cout << 1 << endl;
            cout << (2*b+a)/2 << endl;
        } else {
            int s1 = ((2*b+a)+r)/2, s2 = ((2*b+a)-r)/2;
            if(s1 > s2) swap(s1, s2);
            if(st == 0) {
                if(s1 > 0) cout << 1 << endl << s2 << endl;
                else if(s2 > 0) cout << 1 << endl << s1 << endl;
                else cout << 2 << endl << s1 << ' ' << s2 << endl;
            } else {
                if(s1 < 0) cout << 1 << endl << s2 << endl;
                else if(s2 < 0) cout << 1 << endl << s1 << endl;
                else cout << 2 << endl << s1 << ' ' << s2 << endl;
            }
        }
    }
    return 0;
}