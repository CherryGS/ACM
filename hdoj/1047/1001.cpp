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
int a[505];
ll dp[2][505][505];

bool check(int i, int j) {
    return a[i] >= a[j] && (a[i] == 0 || a[j] == 0 || a[i] + a[j] == 0);
}

int cacu(int i, int j) {
    return (a[i] == 0 && a[j] == 0) ? m : 1;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    memset(dp, 0, sizeof dp);
    for(int i=1; i<=n-1; i++) {
        if(check(i, i+1)) { 
            dp[0][i][i+1] = cacu(i, i+1);
        }
    }
    for(int le=3; le<n; le+=2) {
        for(int i=1; i<=n-le; i++) {
            if(check(i, i+le)) {
                // cout << i << ' ' << i+le << ' ' << dp[i+1][i+le-1] << endl;
                dp[0][i][i+le] = (((dp[0][i+1][i+le-1] + dp[1][i+1][i+le-1]) % mod1) * cacu(i, i+le)) % mod1;
            }
            for(int j=i+1; j<i+le; j+=2) {
                // cout << i << ' ' << j << ' ' << i+le << ' ' << dp[i][j] << ' ' << dp[j+1][i+le] << endl;
                dp[1][i][i+le] = (dp[1][i][i+le] + ((dp[0][i][j] + dp[1][i][j]) % mod1) * dp[0][j+1][i+le] % mod1) % mod1;
                // cout << dp[i][i+le] << endl;
            }
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) { cout << dp[i][j] << ' '; }
    //     cout << endl;
    // }
    cout << (dp[0][1][n] + dp[1][1][n]) % mod1 << '\n';
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