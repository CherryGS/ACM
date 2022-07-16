#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

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

int m, n, t;
double p[1001][51];
double dp[1001][51][51];
double sum[1001];

int solve(cint T) {
    memset(dp, 0, sizeof dp);
    cin >> m >> t >> n;
    if(m == 0 && t == 0 && n == 0) { return true; }
    for(int i=1; i<=t; i++) {
        for(int j=1; j<=m; j++) {
            cin >> p[i][j];
        }
    }
    for(int i=1; i<=t; i++) { dp[i][0][0] = 1.0; }
    for(int i=1; i<=t; i++) {
        for(int j=1; j<=m; j++) {
            for(int k=j; k>=0; k--) {
                if(k) {
                    dp[i][j][k] += dp[i][j-1][k-1] * p[i][j];
                }
                dp[i][j][k] += dp[i][j-1][k] * (1.0-p[i][j]);
            }
        }
    }
    double p = 1.0 , q = 1.0;
    for(int i=1; i<=t; i++) { p *= (1.0 - dp[i][m][0]); }
    for(int i=1; i<=t; i++) {
        double tmp = .0;
        for(int j=n; j<=m; j++) { tmp += dp[i][m][j]; }
        q *= (1.0 - dp[i][m][0] - tmp);
    }
    printf("%.3lf\n", p-q);
    return false;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=100000;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        if(solve(_T)) { break; }
    return 0;
}