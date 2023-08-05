#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll t, r, g, b;

ll sol(ll x, ll y, ll z) {
    if(abs(y-z)%3) return inf_ll;
    else return abs(y-z)/3 + max(y, z) - abs(y-z)/3;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> r >> g >> b;
        ll ans = inf_ll;
        ans = min(ans, sol(r, g, b));
        ans = min(ans, sol(g, b, r));
        ans = min(ans, sol(b, r, g));
        if(ans < inf_ll) cout << ans << endl;
        else cout << -1 << endl;
    }  
    return 0;
}