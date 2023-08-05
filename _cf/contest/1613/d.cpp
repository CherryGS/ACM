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
int a[500500];
ll dp[2][500500];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll s = 0;
    dp[1][0] = 1;
    for(int i=1; i<=n; i++) {
        dp[0][a[i]] += dp[0][a[i]];
        if(a[i] == 0) ++ dp[0][0];
        if(a[i]) dp[1][a[i]] += dp[1][a[i]];
        dp[1][a[i]+2] += dp[1][a[i]+2];
        if(a[i] >= 1) dp[0][a[i]] += dp[0][a[i]-1];
        if(a[i] >= 2) dp[1][a[i]] += dp[0][a[i]-2];
        if(a[i] == 1) ++ dp[1][1];

        dp[1][a[i]] %= mod2;
        dp[1][a[i]+2] %= mod2;
        dp[1][a[i]] %= mod2;
        dp[0][a[i]] %= mod2;
    }
    ll ans = mod2 - dp[1][0];
    // for(int i=0; i<=n; i++)
    //     cout << dp[0][i] << ' ' << dp[1][i] << endl;
    for(int i=0; i<=n; i++) ans = (ans + dp[0][i] + dp[1][i]) % mod2;
    for(int i=0; i<=n; i++) dp[0][i] = dp[1][i] = 0;
    cout << ans << endl;
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