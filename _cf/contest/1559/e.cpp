#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
ll l[51], r[51];
ll dp[51][100100];

ll sol(cint x) {
    for(int i=0; i<=m/x; i++) dp[0][i] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m/x; j++) {
            dp[i][j] = 0;
            int dl = ceil((double)l[i]/x), dr = r[i]/x;
            if(dl > dr) return 0;
            if(j-dl >= 0) dp[i][j] += dp[i-1][j-dl];
            if(j-dr-1 >= 0) dp[i][j] -= dp[i-1][j-dr-1];
            dp[i][j] += dp[i][j-1];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    return dp[n][m/x];
}

int check(int x) {
    if(x == 1) return 1;
    int num = 0;
    int r = sqrt(x);
    for(int i=2; i<=r; i++) {
        if(!(x%(i*i))) return 2;
        if(!(x%i)) { 
            ++ num;
            x /= i;
        }
    }
    if(x > 1) ++num;
    return !(num&1);
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> l[i] >> r[i];
    ll ans = 0;
    for(int i=1; i<=m; i++) {
        if(check(i) == 1) ans += sol(i);
        else if(check(i) == 0) ans -= sol(i);
        ans = (ans+mod) % mod;
    }
    cout << ans << endl;
    return 0;
}