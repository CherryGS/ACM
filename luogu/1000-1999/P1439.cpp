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
int a[100100];
int dp[100100];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int ans=0;
    for(int i=1; i<=n; i++) {
        int k = lower_bound(dp, dp+n+1, a[i]) - dp;
        cout << k << endl;
        dp[k+1] = a[i];
        ans = max(ans, k+1);
    }
    cout << ans;
    return 0;
}