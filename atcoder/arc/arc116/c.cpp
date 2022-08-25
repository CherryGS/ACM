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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll jie[400200];
ll pre[200200];
int n, m;
int vis[200200];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

void init() {
    jie[0] = 1;
    for(int i=1; i<=n+m; i++)
        jie[i] = (jie[i-1]*i) % mod;
    
    pre[0] = 1;
    for(int i=1; i<=m; i++) {
        pre[i] = (jie[n+i-1]*ksm((jie[i]*jie[n-1])%mod, mod-2)) % mod;
    }
    for(int i=2; i<=m; i++)
        if(!vis[i])
            for(int j=1; i*j<=m; j++)
                vis[i*j] = i;
}

ll sol(int x) {
    ll ans = 1;
    int r = 0, s = 0;
    while(x != 1) {
        s = 0;
        r = vis[x];
        while(!(x%r)) {
            ++s;
            x /= r;
        }
        ans = (ans*pre[s]) % mod;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    init();
    ll ans = 0;
    for(int i=1; i<=m; i++) {
        ans = (ans + sol(i)) % mod;
    }
    cout << ans << endl;
    return 0;
}