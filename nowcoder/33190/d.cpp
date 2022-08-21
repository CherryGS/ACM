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
int dp[2][300300];
char s[300300];
vector<int> to[300300];
ll ans;

void dfs(int u, int fa) {
    bool r = s[u-1] - '0';
    dp[0][u] = dp[1][u] = 1;
    ll sum = 0;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u);
            dp[r][u] = 1ll * dp[r][u] * (dp[r][v]+1) % mod1;
            dp[r^1][u] = 1ll * dp[r^1][u] * (dp[r^1][v]+1) % mod1;
            sum = (sum + dp[r^1][v]) % mod1;
        }
    }
    dp[r^1][u] = (dp[r^1][u] - 1 + mod1) % mod1;
    ans = (ans + dp[r][u] + dp[r^1][u] - sum + mod1) % mod1;
    // cout << u << ' ' << dp[r][u] + dp[r^1][u] - sum << ' ' << dp[r][u] << ' ' << dp[r^1][u] << ' ' << sum << endl;
}

void solve(cint T) {
    n = 0;
    cin >> n;
    if(n == 0) { return; }
    cin >> s;
    ans = 0;
    for(int i=1; i<=n; i++) { to[i].clear(); }
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 1);
    // for(int i=1; i<=n; i++) { cout << dp[0][i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n; i++) { cout << dp[1][i] << ' '; }
    // cout << endl;
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=100;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}