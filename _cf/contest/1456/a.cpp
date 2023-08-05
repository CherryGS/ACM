#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, p, k, x, y;
ll dp[100100];
string a;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> p >> k;
        cin >> a >> x >> y;
        ll nx = -p*y, tmp;
        memset(dp, 0x3f, sizeof dp);
        for(int i=p; i<=n; i++) {
            if(a[i-1] == '1') tmp = 0;
            else tmp = x;
            dp[i] = nx + i*y + tmp;
            nx = min(nx, dp[i-k+1] - (i+1)*y);
        }
        ll ans = inf_int;
        for(int i=p; i<=n; i++)
            if(i >= n-k+1) ans = min(ans, dp[i]);
            else ans = min(ans, dp[i] + (n-k+1-i) * y);
        cout << ans << endl;
    }
    return 0;
}