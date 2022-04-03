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
int dp[2][200200];
int loc[30];
char s[200200];

void solve(cint T) {
    cin >> s;
    n = strlen(s);
    memset(loc, 0, sizeof loc);
    for(int i=0; i<=n; i++) { dp[0][i] = dp[1][i] = hf_int; }
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        int r = loc[s[i]-'a'];
        // cout << s[i] << ' ' << r << endl;
        dp[1][i+1] = min(dp[1][i+1], dp[0][i]);
        dp[0][i+1] = min(dp[0][i+1], dp[1][r] + (i+1)-r-1);
        dp[0][i+1] = min(dp[0][i+1], dp[0][i] + 1);
        loc[s[i]-'a'] = i+1;
    }
    // for(int i=1; i<=n; i++) { cout << dp[0][i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n; i++) { cout << dp[1][i] << ' '; }
    // cout << endl;
    cout << min(dp[0][n], dp[1][n]+1) << '\n';
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