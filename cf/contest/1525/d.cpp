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
const int inf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[5050], ct1;
int b[5050], ct2;
int dp[5050][5050];

int main() {
    cin >> n;
    int st;
    for(int i=1; i<=n; i++) {
        cin >> st;
        if(st) a[++ct1] = i;
        else b[++ct2] = i;
    }
    memset(dp, 0x3f, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    int ans = inf_int;
    for(int i=1; i<=ct1; i++)
        for(int j=1; j<=ct2; j++) {
            if(dp[i-1][j-1] < inf_int) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(a[i]-b[j]));
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if(i == ct1) ans = min(ans, dp[i][j]);
        }
    // for(int i=1; i<=ct1; i++) {
    //     for(int j=1; j<=ct2; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    if(ans == inf_int) ans = 0;
    cout << ans << endl;

    return 0;
}