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
int dp[52][2];
int mp[51];
ll x;
ll a[51];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> x;
    for(int i=n; i; i--)
        while(x >= a[i]) {
            ++mp[i];
            x -= a[i];
        }
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i=1; i<=n; i++) {
        if(mp[i]) {
            dp[i+1][1] += dp[i][0] + dp[i][1];
            dp[i+1][0] += dp[i][0];
            if(a[i+1]/a[i] != mp[i] + 1) dp[i+1][0] += dp[i][1];
        }
        else {
            dp[i+1][1] += dp[i][1];
            dp[i+1][0] += dp[i][1];
        }
    }
    cout << dp[n+1][0] + dp[n][0];
    return 0;
}