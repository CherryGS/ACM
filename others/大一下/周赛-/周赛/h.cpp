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
const int bs=500000;

int n;
int dp[500050][2];

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    int a;
    int mx=0;
    dp[0][0]=0;
    int k=0;
    for(int i=1; i<=n; i++, k^=1) {
        cin >> a;
        for(int j=0; j <= mx; j++) if(dp[j][k]>=0){
            int k1 = abs(j-a);
            dp[k1][k^1] = max(dp[k1][k^1], dp[j][k]+a);
            dp[j][k^1] = max(dp[j][k^1], dp[j][k]);
            dp[j][k^1] = max(dp[j][k^1], dp[j][k]);
            if(j+a < bs) {
                dp[j+a][k^1] = max(dp[j+a][k^1], dp[j][k]+a);
                mx = max(mx, j+a);
            }
        }
        for(int j=0; j<=mx; j++) dp[j][k]=-1;
    }
    if(dp[0][k] <= 0) cout << -1 << endl;
    else cout << dp[0][k]/2 << endl;
    return 0;
}
/*
5
1 2 3 2 1

5
1 2 3 3 3

6
100 99 101 92 77 999
*/