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

int n, m;
string a, b;
int dp[5050][5050];
int ans;

int main() {
    cin >> n >> m;
    cin >> a >> b;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
            } else dp[i][j] = max(dp[i][j], dp[i-1][j-1]-2);
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}