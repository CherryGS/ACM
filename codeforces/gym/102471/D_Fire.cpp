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

ll n, k;
ll a[100100];
ll dp1[100100], dp2[100100];
ll siz[100100];
ll mn[100100];
ll s_mn[100100];
vector<int> to[100100];
pair<ll,ll> q[100100];

// dp1[u]: 初始站在 u 上且 cast 完 u 的子树且回到 u 时温度恰好为 2 时最长的等待时间
// dp2[u]: 初始站在 u 上且 cast 完 u 的子树且不回到 u 时(不考虑 u 的温度)最长的等待时间

void dfs(int u, int f) {
    siz[u] = 1;
    int num = 0;
    for(auto &v: to[u]) {
        if(v != f) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
    if(k == 0) { dp1[u] = a[u]-2; }
    else if(k == 1) { dp1[u] = a[u] - 1; }
    else { dp1[u] = a[u]; }
    dp1[u] = min(dp1[u], a[u] + k - (siz[u]-1)*2 - 2);
    dp2[u] = -1;
    if(siz[u] == 1) { dp2[u] = a[u]; }

    int c = 0;
    for(auto &v: to[u]) {
        if(v != f) {
            q[++c] = {siz[v]*2+dp1[v], v};
        }
    }
    sort(q+1, q+1+c);
    mn[0] = 1e9;
    s_mn[0] = 1e9;
    int s1 = 0;
    for(int i=1; i<=c; i++) {
        dp1[u] = min(dp1[u], dp1[q[i].second] - s1 - 1);
        mn[i] = dp1[q[i].second] - s1 - 1;
        s_mn[i] = min(mn[i], s_mn[i-1]);
        s1 += siz[q[i].second] * 2;
    }
    ll s2 = 1e9, pre;
    for(int i=c; i>=1; i--) {
        pre = 1e9;
        pre = min(pre, a[u] + k - (siz[u]-siz[q[i].second]-1)*2 - 2);
        pre = min(pre, dp2[q[i].second] - (siz[u]-siz[q[i].second]-1)*2 - 1);
        pre = min(pre, s_mn[i-1]);
        pre = min(pre, s2 + siz[q[i].second]*2);
        s2 = min(s2, mn[i]);
        dp2[u] = max(dp2[u], pre);
    }
    dp2[u] = min(dp2[u], a[u]);
}

void solve(cint T) {
    cin >> n >> k;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    dfs(1, 1);

    // for(int i=1; i<=n; i++) { cout << dp1[i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n; i++) { cout << dp2[i] << ' '; }
    // cout << endl;

    if(dp2[1] < 0) { cout << -1 << '\n'; }
    else { cout << dp2[1] << '\n'; }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
