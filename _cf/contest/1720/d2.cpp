#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[300300];
int val[300300];
int dp[2][300001*30];
int tr[2][300001*30], cnt;

void dfs(int u, int x, int step) {
    if(step >= 0) {
        int v = (a[x]>>step) & 1;
        if(tr[v^1][u]) {
            // cout << step << ' ' << x << ' ' << v << ' ' << tr[v^1][u] << ' ' << (1&(x>>step)) << endl;
            val[x] = max(val[x], dp[1&(x>>step)][tr[v^1][u]] + 1);
        }
        if(tr[v][u]) { dfs(tr[v][u], x, step-1); }
    }
    dp[1&((a[x]^x)>>(step+1))][u] = max(dp[1&((a[x]^x)>>(step+1))][u], val[x]);
}

void solve(cint T) {
    cin >> n;
    for(int i=0; i<n; i++) { val[i] = 1; }
    for(int i=0; i<=cnt; i++) { dp[0][i] = tr[0][i] = dp[1][i] = tr[1][i] = 0; }
    cnt = 0;
    for(int i=0; i<n; i++) { cin >> a[i]; a[i] ^= i; }
    int u, v;  
    for(int i=0; i<n; i++) {
        u = 0;
        for(int j=30; j>=0; j--) {
            v = 1 & ((a[i])>>j);
            if(tr[v][u] == 0) { tr[v][u] = ++cnt; }
            u = tr[v][u];
        }
        dfs(0, i, 30);
    }
    // for(int i=0; i<n; i++) { cout << val[i] << ' '; }
    // cout << endl;
    int ans = 0;
    for(int i=0; i<n; i++) { ans = max(ans, val[i]); }
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}