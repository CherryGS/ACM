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

const int mod1 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll f[1110000];
ll inv[1110000];
ll dp[1001000];
ll ans[1000100];

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
    if(n < m) { return 0; }
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
    ll sum = 0;
    for(int i=n/3; i>=1; i--) {
        ll t = sum;
        dp[i] = ksm(26, n-i*3) * C(n-i*3+i, i) % mod1;
        cout << i << ' ' << dp[i] << ' ' << t << endl;
        sum = ((-sum - dp[i] + mod1) % mod1 + mod1) % mod1;
        dp[i] = ((dp[i] + t) % mod1 + mod1) % mod1;
        ans[i] = (dp[i] - dp[i+1] + mod1) % mod1;
    }
    ans[0] = ksm(26, n);
    for(int i=1; i<=n; i++) {
        ans[0] = (ans[0] - ans[i] + mod1) % mod1;
    }
    for(int i=0; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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