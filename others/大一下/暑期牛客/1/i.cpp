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

int n;
int p[5050];
ll f[5050][5050], g[5050][5050];
int q[5050], cnt;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

void debug() {
    cout << (5*ksm(6, mod-2) + 3*ksm(3, mod-2)) % mod << endl;
    cout << ksm(3, mod-2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    f[0][0] = 1;
    ll ans = -1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(f[i][j]) {
                cnt = 0;
                for(int k=i+1; k<=n; k++) {
                    if(p[k] > p[i] && p[k] > p[j]) {
                        q[++cnt] = k;
                    }
                }
                ans = (ans+f[i][j]) % mod;
                ll r = ksm(cnt, mod-2);
                for(int k=1; k<=cnt; k++) {
                    g[q[k]][j] = (g[q[k]][j] + f[i][j]*r) % mod;
                }
            }
            if(g[i][j]) {
                cnt = 0;
                for(int k=j+1; k<=n; k++) {
                    if(p[k] > p[i] && p[k] > p[j]) {
                        q[++cnt] = k;
                    }
                }
                ans = (ans+g[i][j]) % mod;
                ll r = ksm(cnt, mod-2);
                for(int k=1; k<=cnt; k++) {
                    f[i][q[k]] = (f[i][q[k]] + g[i][j]*r) % mod;
                }
            }
            // printf("%d-%d-%lld-%lld-%lld\n", i, j, ans, f[i][j], g[i][j]);
        }
    }
    // debug();
    cout << ans << endl;
    return 0;
}