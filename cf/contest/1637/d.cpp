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
ll a[101], b[101];
ll dp[2][10010];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    ll ans = 0;
    for(int i=1; i<=n; i++) ans += (a[i] * a[i] + b[i] * b[i]) * (n-1);
    // for(int i=1; i<=n; i++) ans += (a[i] * a[i] + b[i] * b[i]) * (i-1);
    bool st = false;
    ll mx = 0, sum = 0;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i=n; i>=1; i--, st ^= 1) {
        for(int j=mx; j>=0; j--) {
            if(dp[st][j] < inf_ll/2) {
                dp[st^1][j+a[i]] = min(dp[st^1][j+a[i]], dp[st][j] + a[i]*j + b[i]*(sum - j));
                dp[st^1][j+b[i]] = min(dp[st^1][j+b[i]], dp[st][j] + b[i]*j + a[i]*(sum - j));
                mx = max(mx, j+a[i]);
                mx = max(mx, j+b[i]);
            }
        }
        memset(dp[st], 0x3f, sizeof dp[st]);
        sum += a[i] + b[i];
    }
    // cout << ans << endl;
    ll ans1 = inf_ll;
    for(int i=0; i<=mx; i++) ans1 = min(ans1, dp[st][i]);
    cout << ans + ans1*2 << endl;
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