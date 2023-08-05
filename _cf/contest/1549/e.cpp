#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, q;
ll to[3003000];
ll ans[3003000];
ll inv[3003000];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(cint x, cint y) {
    if(y > x) return 0;
    return to[x] * inv[y] % mod * inv[x-y] % mod;
}

void init() {
    int mx_n = 3000020;
    to[0] = 1;
    for(int i=1; i<=mx_n; i++)
        to[i] = to[i-1]*i%mod;
    inv[mx_n] = ksm(to[mx_n], mod-2);
    for(int i=mx_n-1; i>=0; i--)
        inv[i] = (inv[i+1]*(i+1)) % mod;
}

int main() {
    init();
    scanf("%d%d", &n, &q);
    ans[0] = n;
    n *= 3;
    ll div = ksm(3, mod-2);
    for(int i=1; i<=n; i++) {
        ll pre = (C(n+3, i+1) - C(1, i) - C(2, i) + mod + mod) % mod;
        if(i >= 1) pre = (pre - ans[i-1]*3 + mod + mod + mod) % mod;
        if(i >= 2) pre = (pre - ans[i-2] + mod) % mod;
        ans[i] = pre * div % mod;
    }
    for(int i=1; i<=q; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%lld\n", ans[tmp]);
    }
    return 0;
}