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
        int s1 = inf_int, s2 = inf_int;
        cin >> a >> b;
        if(a == 0) {
            cout << 1 << endl;
            cout << b << endl;
            continue;
        }
        if(a > 0)
        for(int i=max(0, b); i<=1e4; i++) {
            if(a*i == (i-b)*(i-b)) {
                if(s1 == inf_int) s1 = i;
                else if(s2 == inf_int) s2 = i;
            }
        }
        if(a < 0)
        for(int i=b; i<=0; i++) {
            if(a*i == (i-b)*(i-b)) {
                if(s1 == inf_int) s1 = i;
                else if(s2 == inf_int) s2 = i;
            }
        }
        if(s1 != inf_int) {
            if(s2 != inf_int) {
                cout << 2 << endl << s1 << ' ' << s2 << endl;
            } else cout << 1 << endl << s1 << endl;
        }
    }
    return 0;
}