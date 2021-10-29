#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, p;
ll q;

ll mod = 998244353;
ll dp[500500][2];
ll d[500500];
ll son[500500];
ll prob[500500];

vector<ll> e[500500];

ll ksm(ll bs, ll x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans * bs) % mod;
        bs = (bs * bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll ans = 0;

void dfs(cint loc, cint fa) {
    // cout << loc << endl;
    for(int v: e[loc]) {
        if(v != fa) {
            dfs(v, loc);
        }
    }
    ll pre = 0, pre1 = 0;
    for(int v: e[loc]) {
        if(v != fa) {
            prob[loc] = (prob[loc]*prob[v]) % mod;
        }
    }
    if(son[loc]) {
        for(int v: e[loc]) {
            if(v != fa) {
                d[loc] = (d[loc] + (d[v])*q%mod*ksm(p, son[loc]-1)%mod*(prob[loc]*ksm(prob[v], mod-2)%mod)%mod)%mod;
            }
        }
        prob[loc] = (prob[loc] * (ksm(p, son[loc]) % mod + (son[loc]*ksm(p, son[loc]-1) * q % mod))%mod) % mod;
        ans = (ans + d[loc]) % mod;
    }
    d[loc] = (d[loc] + prob[loc]) % mod;
}

void debug() {
    for(int i=1; i<=n; i++)
        cout << d[i] << ' ';
    cout << endl;
    cout << son[1] << "---" << endl;
    cout << ((d[4]+4)*(ksm(p, son[1]-1)*q%mod))%mod << endl;
}

int main() {
    cin >> n >> p;
    q = (mod + 1 - p) % mod;
    int u;
    prob[1] = 1;
    for(int i=2; i<=n; i++) {
        prob[i] = 1;
        cin >> u;
        e[u].push_back(i);
        // e[i].push_back(u);
        son[u]++;
    }
    dfs(1, 1);
    // debug();
    cout << ans << endl;
    cout << ((3*p*p%mod*q)%mod+(5*p*q%mod*q)%mod) % mod << endl;
    cout << ((2*p*q%mod) + p*p%mod*q%mod + q)%mod << endl;
    return 0;
}