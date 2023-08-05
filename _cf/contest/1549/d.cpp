#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
ll a[200200];
ll b[200200];
ll dp[200200][21];

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<n; i++) b[i] = abs(a[i+1]-a[i]);
        for(int i=1; i<n; i++)
            for(int j=0; j<=20; j++) dp[i][j] = 1;
        for(int i=1; i<n-1; i++) dp[i][0] = gcd(b[i], b[i+1]);
        for(int j=1; j<=20; j++) {
            for(int i=1; i<n; i++) {
                int r = min(n-1, i+(1<<(j-1)));
                dp[i][j] = gcd(dp[i][j-1], dp[r][j-1]);
            }
        }
        int ans = 0;
        for(int i=1; i<n; i++) {
            int r = i;
            ll c = 0;
            for(int j=20; j>=0; j--) {
                ll pre = gcd(dp[r][j], c);
                if(pre > 1) {
                    r = min(n-1, r+(1<<j));
                    c = pre;
                }
            }
            ans = max(ans, r-i+(b[i] != 1));
        }
        cout << ans+1 << endl;
    }
    return 0;
}