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

int n, m;
char s[505][505];
ll dp[2][505];

void solve(cint T) {
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<=m; i++) dp[0][i] = s[0][i] - '0';
    bool st = 0;
    for(int i=1; i<n; i++, st ^= 1) {
        for(int j=m; j>=0; j--) if(dp[st][j]) {
            for(int k=0; k<=m; k++) {
                if(s[i][k] == '1' && j+k <= m) {
                    dp[st^1][j+k] += dp[st][j];
                    dp[st^1][j+k] %= mod2;
                }
            }
        }
        memset(dp[st], 0, sizeof dp[st]);
    }

    ll ans = 0;
    for(int i=0; i<=m; i++) (ans += dp[st][i]) %= mod2;
    cout << ans << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}