#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
vector<int> to[100100];
ll dp[401][101][2][2];

void dfs(cint loc, cint fa) {
    for(int v: to[loc]) {
        if(v != fa) dfs(v, loc);
    }
    dp[loc][0][0][1] = dp[loc][1][1][0] = 1;
    for(int v: to[loc]) {
        for(int i=k; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                memset(dp[loc][i], 0, sizeof dp[loc][i]);
                ll s1 = dp[loc][i-j][0][0] % mod, s2 = s1 + dp[loc][i-j][0][1] % mod, s3 = s2 + dp[loc][i-j][1][0] % mod;
                dp[loc][i][0][0] += dp[v][j][0][0]*s1 + dp[v][j][1][0]*s2;
                dp[loc][i][0][1] += dp[v][j][0][0]*dp[loc][i-j][0][1];
                dp[loc][i][1][0] += (dp[v][j][0][0]+dp[v][j][0][1]+dp[v][j][1][0])*dp[loc][i-j][1][0];
                dp[loc][i][0][0] %= mod;
                dp[loc][i][0][1] %= mod;
                dp[loc][i][1][0] %= mod;
                if(i-j-1 >= 0) {
                    dp[loc][i][1][0] += dp[v][j][0][0]*(dp[loc][i-j-1][0][0] + dp[loc][i-j-1][0][1]) % mod;
                    dp[loc][i][1][0] += dp[v][j][0][1]*(dp[loc][i-j-1][0][0] + dp[loc][i-j-1][0][1]) % mod;
                    dp[loc][i][1][0] += dp[v][j][1][0]*(dp[loc][i-j-1][0][0] + dp[loc][i-j-1][0][1]) % mod;
                    dp[loc][i][1][0] %= mod;
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    if(n > 4*k) cout << 0 << endl;
    else {
        dfs(1, 1);
        cout << (dp[1][k][0][0]+dp[1][k][1][0]) % mod << endl;
    }
    return 0;
}