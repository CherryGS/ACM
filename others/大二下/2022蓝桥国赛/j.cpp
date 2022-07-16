// n^2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int n;
int dp[10005][10005];

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0][0] = 1;
    for(int i=1; i<=n*2; i++) {
        for(int j=0; j<=i; j++) {
            if(j > 0) { dp[i][j] = (0ll + dp[i][j] + dp[i-1][j-1]) % mod; }
            dp[i][j] = (0ll + dp[i][j] + dp[i-1][j+1]) % mod;
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            ans = (ans + dp[(n-i)*2+1][j*2-1]) % mod;
        }
    }
    cout << ans << '\n';
    return 0;
}