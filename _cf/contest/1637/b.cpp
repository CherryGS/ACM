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
int a[101];
int dp[101];
bool vis[101];

void solve(cint T) {
    cin >> n;
    ll ans = 0;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        memset(dp, 0, sizeof(dp));
        for(int j=i; j<=n; ++j) {
            int mex = 0;
            memset(vis, 0, sizeof vis);
            for(int k=j; k>=i; --k) {
                if(a[k] < 100) vis[a[k]] = 1;
                while(vis[mex]) ++ mex;
                dp[j] = max(dp[j], dp[k-1] + mex + 1);
            }
            ans += dp[j];
        }
    }
    cout << ans << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}