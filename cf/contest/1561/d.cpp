#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
ll dp[4000200];
ll sum[4000200];

int main() {
    cin >> n >> m;
    dp[n] = 1;
    sum[n] = 1;
    for(int i=n-1; i>=1; i--) {
        dp[i] = (dp[i] + sum[i+1]) % m;
        for(int j=2; i*j<=n; j++) {
            int r = min(n+1, i*j+j);
            dp[i] = (dp[i] + sum[i*j]-sum[r]+m) % m;
        }
        sum[i] = (sum[i] + sum[i+1] + dp[i]) % m;
    }
    cout << dp[1] << endl;
    return 0;
}