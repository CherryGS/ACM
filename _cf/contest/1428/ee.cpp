#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll a[1001000];
ll ans = inf_ll;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs);
        bs = bs*bs;
        x >>= 1;
    }
    return ans;
}

ll cacu(ll x, int y) {
    int r = x%y;
    ll c = x/y;
    return (c+1)*(c+1)*r + c*c*(y-r);
}

void dfs(ll res, cint dk, cint loc, cint lim) {
    if(loc == n+1) {
        ans = min(ans, res);
        return;
    }
    for(int i=dk; (n-loc+1)*i <= lim; i++)
        dfs(res+cacu(a[loc], i), i, loc+1, lim-i);
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    dfs(0, 1, 1, k);
    cout << ans << endl;
    return 0;
}