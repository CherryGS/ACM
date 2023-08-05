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
ll p, a, b, c;

ll get_(ll x) {
    if(x >= p) return x-p;
    return ((p/x)+((p%x)!=0))*x-p;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> p >> a >> b >> c;
        ll aa = get_(a);
        ll bb = get_(b);
        ll cc = get_(c);
        if((aa) < (bb)) {
            if((aa) < (cc)) {
                cout << aa;
            } else cout << cc;
        } else {
            if((bb) < (cc)) cout << bb;
            else cout << cc;
        }
        cout << endl;
    }
    return 0;
}