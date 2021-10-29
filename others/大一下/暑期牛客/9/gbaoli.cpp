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
bool vis[101];

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
ll pre_ans = 0;

int dfs(cint loc, cint fa, cint st) {
    // cout << endl;
    // cout << loc << ' ' << fa << ' ' << endl;
    int num = 0;
    for(int v:e[loc]) {
        if(v != fa) {
            if(st & (1<<(v-1))) {
                if(vis[loc]) { pre_ans = -1; return 0;}
                vis[loc] = 1;
            }
            num += dfs(v, loc, st);
            if(pre_ans == -1) return 0;
        }
    }
    // cout << loc << "-------" << num << endl;
    if(pre_ans != -1) pre_ans = (pre_ans + num) % mod;
    if(!(st&(1<<(loc-1)))) return 0;
    return num+1;
}

void sol(cint x) {
    memset(vis, 0, sizeof vis);
    int num = 0;
    pre_ans = 0;
    for(int i=0; (1<<i)<=x; i++) {
        if(x&(1<<i)) ++num;
    }
    dfs(1, 1, x);
    if(pre_ans != -1)
    ans = (ans + (pre_ans*(ksm(p, n-num-1)*ksm(q, num)%mod))%mod)%mod;
    // cout << pre_ans << "---" << x << endl;
}

int main() {
    cin >> n >> p;
    q = (mod + 1 - p) % mod;
    int u;
    for(int i=2; i<=n; i++) {
        cin >> u;
        e[u].push_back(i);
        // e[i].push_back(u);
        son[u]++;
    }
    for(int i=0; i<=(1<<n)-1; i+=2)
        sol(i);
    // debug();
    cout << ans << endl;
    return 0;
}