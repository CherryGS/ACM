#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[200200];
ll dp[200200][2];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    ll st = dp[0][0];
    dp[1][0] = 0;
    for(int i=2; i<=n; i++) {
        if(dp[i-1][0] < st) {
            dp[i][1] = min(dp[i][1], dp[i-1][0]+(a[i]-a[i-1])/2);
        }
        if(dp[i-1][1] < st) {
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
            dp[i][1] = min(dp[i][1], dp[i-1][1]+(a[i]-a[i-1])/2);
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}