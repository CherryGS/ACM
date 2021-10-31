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

int n, m, p, q;
int dp[2][505][1005];
bool mp[505][505];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p >> q;
    if(p+q > m+n) cout << 0 << endl;
    else {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cin >> mp[i][j];
                if(p < q) mp[i][j] ^= 1;
            }
        }
        if(p < q) swap(p, q);
        bool st = 0;
        dp[st^1][1][mp[1][1]] = 1;
        for(int i=1; i<=n; i++, st ^= 1) {
            for(int j=1; j<=m; j++) {
                for(int k=0; k<=n+m-p-1; k++) {
                    if(k-mp[i][j] >= 0) {
                        dp[st^1][j][k] += dp[st][j][k-mp[i][j]];
                        dp[st^1][j][k] %= mod2;
                        dp[st^1][j][k] += dp[st^1][j-1][k-mp[i][j]];
                        dp[st^1][j][k] %= mod2;
                    }
                }
            }
            // cout << dp[st^1][2][1] << " --- " << endl;
            memset(dp[st], 0, sizeof dp[st]);
        }
        ll ans = 0;
        for(int i=q; i<=n+m-p-1; i++) { ans = (ans + dp[st][m][i]) % mod2; }
        cout << ans << endl;
    }
    return 0;
}