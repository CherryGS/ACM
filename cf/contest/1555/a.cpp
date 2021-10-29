#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ull n;
ull dp[200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ull ans = 0;
        ans += (n/120)*300;
        n %= 120;
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        ull pre = inf_ll/2;
        for(int i=0; i<=n; i++) {
            dp[i+6] = min(dp[i+6], dp[i]+15);
            dp[i+8] = min(dp[i+8], dp[i]+20);
            dp[i+10] = min(dp[i+10], dp[i]+25);
        }
        for(int i=0; i<=10; i++)
            pre = min(pre, dp[i+n]);
        cout << ans + pre << endl;
    }
    return 0;
}