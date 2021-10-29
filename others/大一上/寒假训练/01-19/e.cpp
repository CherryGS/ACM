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

ll n;
int dp[180];
int mx, num;

int main() {
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    cin >> n;
    while(n) {
        int k = n%10;
        n /= 10;
        ++num;
        for(int i=mx; i>=0; i--)
            if(dp[i]>=0) dp[i+k] = max(dp[i+k], dp[i]+1);
        mx = mx+k;
    }
    int ans = -1;
    for(int i=mx; i>0; i--)
        if(!(i%3)) ans = max(ans, dp[i]);
    if(ans == -1) cout << -1 << endl;
    else cout << num-ans << endl;
    return 0;
}