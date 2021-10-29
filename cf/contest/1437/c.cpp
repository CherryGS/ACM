#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int dp[202][402];
int a[202];

int main() {
    int q;
    cin >> q;
    while(q--) {
        int mx=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        int ans=inf_int;
        for(int i=0; i<=n; i++)
            for(int j=1; j<=2*n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
                if(i) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(a[i]-j));
                if(i==n) ans = min(ans, dp[i][j]);
            }
        cout << ans << endl;
    }
    return 0;
}