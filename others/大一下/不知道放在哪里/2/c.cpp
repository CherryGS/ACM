#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n;

int gcd(cint x, cint y) {
    return y == 0? x : gcd(y, x%y);
}

int main() {
    cin >> n;
    if(n > 3) {
        ll ans = 1;
        int r = 24;
        for(int i=0; i<=3; i++) {
            int s = gcd(n-i, r);
            ans *= (n-i)/s;
            r /= s;
        }
        cout << ans << endl;  
    }
    else cout << 0 << endl;
    return 0;
}