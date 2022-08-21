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

int n, k, t;
int dp[65][65][65*65];

void solve(cint T) {
    cin >> n >> k >> t;
    dp[0][0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int s=0; s<=t; s++) {
            ll sum = 0;
            bool flag = false;
            for(int j=0; j<k; j++) { sum = (sum + dp[i-1][j][s]) % mod2; if(dp[i-1][j][s]) { flag = true; } }
            for(int j=0; j<k; j++) {
                
            }
            // cout << sum << endl;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<k; j++) {
            cout << dp[i][j][t+1] << ' ';
        }
        cout << endl;
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<k; j++) {
            cout << dp[i][j][t] << ' ';
        }
        cout << endl;
    }
    ll ans = 0;
    for(int i=0; i<k; i++) { ans = (ans + dp[n][i][t] - dp[n][i][t+1] + mod2) % mod2; }
    cout << (ans-1+mod2) % mod2 << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}