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
ll t[1000100];
ll w[1000100];
ll node[1000100];
ll val[2][1000100];

int lb(int x) { return x& -x;}

void add(int x, ll val) {
    while(x <= n) {
        node[x] = max(node[x], val);
        x += lb(x);
    }
}

ll query(int x) {
    ll ans = 0;
    while(x) {
        ans = max(ans, node[x]);
        x -= lb(x);
    }
    return ans;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i] >> w[i];
    ll sum = 0;
    for(int i=1; i<=n; i++) sum += w[i];
    for(int i=1; i<=n; i++) {
        ll now = query(t[i]-1) + w[i];
        val[0][i] = now;
        add(t[i], now);
    }
    memset(node, 0, sizeof node);
    for(int i=n; i>=1; i--) {
        ll now = query(t[i]-1) + w[i];
        val[1][i] = now;
        add(t[i], now);
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, val[0][i] + val[1][i] - w[i]);
    cout << sum - ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}