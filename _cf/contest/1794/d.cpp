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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[10010];
int fac[10010];
int inv[10010];
ll dp[4101][2051];
bool prim[1000010];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod; }
        bs = bs * bs % mod;
        x >>= 1; 
    }
    return ans;
}

ll C(int n, int m) {
    if(m == 0) { return 1; }
    return 1ll * fac[n] * inv[m] % mod * inv[n-m] % mod;
}

void init() {
    fac[0] = 1;
    for(int i=1; i<=10000; i++) { fac[i] = 1ll * fac[i-1] * i % mod; }
    inv[10000] = ksm(fac[10000], mod-2);
    for(int i=10000-1; i>=0; i--) { inv[i] = 1ll * inv[i+1] * (i+1) % mod;}
    prim[1] = 1;
    for(int i=2; i<=1000000; i++) {
        if(prim[i]) { continue; }
        for(int j=i+i; j<=1000000; j+=i) { prim[j] = 1; }
    }
}

bool solve(cint T) {
    cin >> n; n <<= 1;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    sort(a+1, a+1+n);
    dp[0][0] = 1;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        if(i > 0 && a[i] == a[i+1]) { continue; }
        int r = i+1;
        while(r < n+1 && a[r] == a[i+1]) { ++r; } --r;
        for(int j=0; j<=i; j++) {
            if(prim[a[r]] != 1) dp[r][j+1] = (dp[r][j+1] + 1ll * dp[i][j] * C(i-j+1+r-(i+1)-1, r-(i+1))) % mod;
            dp[r][j] = (dp[r][j] + 1ll * dp[i][j] * C(i-j+1+r-i-1, r-i)) % mod;
        }
    }
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=n; j++) { 
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << dp[n][n/2] << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    init();
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}