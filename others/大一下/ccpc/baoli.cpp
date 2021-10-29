#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll a, b, c, d, n;

ll sol(ll x) {
    ll pre = 0;
    while(x) {
        pre += x%10;
        x /= 10;
    }
    return pre;
}

ll cacu(ll x) {
    ll r = sol(x);
    return a*x*x*r+b*x*x+c*x*r*r+d*x*r;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> n;
        ll ans = inf_ll;
        for(int i=1; i<=n; i++)
            ans = min(ans, cacu(i));
        cout << ans << endl;
    }
    return 0;
}