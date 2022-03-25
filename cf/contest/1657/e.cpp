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

int n, k;
ll dp[300][300];
ll C[303][303];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) ans = (ans * bs) % mod2;
        bs = (bs * bs) % mod2;
        x >>= 1;
    }
    return ans;
}

ll bino(ll x, ll y) {
    return C[x][y];
}

void init() {
    int t = 300;
    for(int i=0; i<=t; i++) { C[i][i] = 1; }
    for(int i=0; i<=t; i++) { C[i][0] = 1; }
    for(int i=1; i<=t; i++) {
        for(int j=1; j<=i; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod2;
        }
    }
}

void solve(cint T) {
    cin >> n >> k;
    dp[0][k+1] = 1;
    for(int i=0; i<=n-2; i++) {
        for(int j=k+1; j>=2; j--) {
            if(dp[i][j]) {
                for(int l=n-1-i; l>=0; l--) {
                    int r = k-j+2;
                    if(!r) ++r;
                    dp[i+l][j-1] += (dp[i][j] * (bino(n-1-i, l) * ksm(r, l*(n-2)-bino(l, 2)-l*i) % mod2)) % mod2;
                    // cout << i+l << ' ' << j-1 << ' '<< dp[i+l][j-1] << ' ' << i << endl;
                    dp[i+l][j-1] %= mod2;
                }
            }
        }
    }
    // for(int i=1; i<=k; i++) cout << dp[1][i] << ' ';
    // cout << endl;
    ll ans = 0;
    for(int i=1; i<=k; i++) { ans = (ans + dp[n-1][i]) % mod2; }
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}