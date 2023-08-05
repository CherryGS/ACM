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
char s[6006];
ll dp[2][6005];
ll vis[2][6005];

void solve(cint T) {
    cin >> n;
    cin >> s;
    const int bs = 3002;
    vis[0][bs] = 1;
    bool st = false;
    for(int i=0; i<n*2; i++, st^=1) {
        for(int j=-min(i, n); j<=min(i, n); j++) {
            if(vis[st][j+bs]) {
                vis[st][j+bs] %= mod;
                if(s[i] == '+' || s[i] == '?') {
                    dp[st^1][j+1+bs] += dp[st][j+bs] + 1ll * abs(j) * vis[st][j+bs];
                    dp[st^1][j+1+bs] %= mod;
                    vis[st^1][j+1+bs] += vis[st][j+bs];
                }
                if(s[i] == '-' || s[i] == '?') {
                    dp[st^1][j-1+bs] += dp[st][j+bs] + 1ll * abs(j) * vis[st][j+bs];
                    dp[st^1][j-1+bs] %= mod;
                    vis[st^1][j-1+bs] += vis[st][j+bs];
                }
            }
        }
        // for(int j=-n; j<=n; j++) { cout << dp[st^1][j+bs] << ' '; }
        // cout << endl;
        memset(dp[st], 0, sizeof dp[st]);
        memset(vis[st], 0, sizeof vis[st]);
    }
    cout << dp[st][bs] << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
