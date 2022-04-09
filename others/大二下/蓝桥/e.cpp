#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

const int mod = 998244353;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod; }
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

ll n, x, y;

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> x >> y;
        ll inv = ksm(y-x, mod-2);
        ans = (ans+1) * ((y*inv) % mod);
        ans %= mod;
    }
    cout << ans;
}   