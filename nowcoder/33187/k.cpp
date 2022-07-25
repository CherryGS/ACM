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
char s[2002];
ll dp[202][202][202];

void solve(cint T) {
    memset(dp, 0, sizeof dp);
    cin >> n >> m;
    cin >> s;
    dp[0][0][0] = 1;
    for(int i=0; i<m; i++) {
        for(int j=0; j<=min(n, i+1); j++) {
            for(int k=0; k<=i; k++) {
                if(dp[i][j][k] == 0) { continue; }
                if(k != 0) {
                    if(s[j] == ')') {
                        dp[i+1][j+1][k-1] = (dp[i+1][j+1][k-1] + dp[i][j][k]) % mod1;
                    }
                    else {
                        // if(i == 3 && j == 2 && k == 1) { cout << " --- " << endl; }
                        dp[i+1][j][k-1] = (dp[i+1][j][k-1] + dp[i][j][k]) % mod1;
                    }
                }
                if(s[j] == '(') {
                    dp[i+1][j+1][k+1] = (dp[i+1][j+1][k+1] + dp[i][j][k]) % mod1;
                }
                else {
                    dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % mod1;
                }
            }
        }
    }
    // for(int l=0; l<=m-n; l++) {
    //     for(int i=0; i<=m; i++) {
    //         for(int j=0; j<=n; j++) {
    //             cout << dp[i][j][l] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    cout << dp[m][n][0] << '\n';
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