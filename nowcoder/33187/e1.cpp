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
ll f[1110000];
ll inv[1110000];
ll dp[3][1000100];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod1; }
        bs = bs * bs % mod1;
        x >>= 1;
    }
    return ans;
}

ll C(int n, int m) {
    return f[n] * inv[m] % mod1 * inv[n-m] % mod1;
}

void init() {
    f[0] = 1;
    for(int i=1; i<=1100000; i++) { f[i] = f[i-1] * i % mod1; }
    inv[1100000] = ksm(f[1100000], mod1-2);
    for(int i=1100000-1; i>=0; i--) { inv[i] = inv[i+1] * (i+1) % mod1; }
}

void solve(cint T) {
    cin >> n;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        dp[0][i] = dp[0][i-1] * 25 + dp[1][i-1] * 24 + dp[2][i-1] * 24;
        dp[0][i] %= mod1;
        dp[1][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
        dp[1][i] %= mod1;
        dp[2][i] = dp[1][i-1];
        dp[2][i] %= mod1;
    }
    cout << (dp[0][n] + dp[1][n] + dp[2][n]) % mod1 << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}