#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll dp[202][402][402];
ll to[402];
ll inv[402];
ll pre[202];
ll cc[404];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs % mod;
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

void init() {
    to[0] = 1;
    for(int i=1; i<=400; i++)
        to[i] = to[i-1] * i % mod;
    inv[400] = ksm(to[400], mod-2);
    for(int i = 399; i; i--)
        inv[i] = inv[i+1] * (i+1) % mod;

    int r = min(n, 2*k);
    cc[1] = n;
    for(int i=2; i<=r; i++)
        cc[i] = cc[i-1] * (n-i+1) % mod;
    for(int i=1; i<=r; i++)
        cc[i] = cc[i] * inv[i] % mod;
}

int main() {
    // freopen("1.in", "r", stdin);
    cin >> n >> k;
    init();
    dp[0][1][1] = 1;
    for(int r=0; r<=k; r++)
        for(int i=1; i<=2*k; i++) {
            for(int j=0; j<=i; j++) {
                if(dp[r][i][j]) {
                    dp[r][i+1][j+1] = (dp[r][i+1][j+1] + dp[r][i][j]) % mod;
                    dp[r+1][i+1][j] = (dp[r+1][i+1][j] + dp[r][i][j] * (i-j)) % mod;
                    if(j) dp[r+1][i+1][j-1] = (dp[r+1][i+1][j-1] + dp[r][i][j]*j) % mod;
                }
            }
        }
    pre[0] = 1;
    for(int i=1; i<=k; i++) {
        ll ans = 0;
        for(int j=i; j<=min(n, 2*i); j++) { 
            ans = (ans + cc[j] * dp[i][j][0]) % mod;
        }
        if(i > 1) ans = (ans + pre[i-2]) % mod;
        pre[i] = ans;
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}