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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[505];
ll dp[505];

int main() {
    char tmp;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        if(tmp == '+') {
            cin >> a[i];
        }
        else a[i] = -1;
    }
    
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] != -1) {
            int mx = 0;
            memset(dp, 0, sizeof dp);
            dp[0] = 1;
            for(int j=1; j<=n; j++) {
                if(j < i) {
                    if(a[j] == -1) {
                        dp[0] = (2*dp[0]) % mod;
                        for(int k=0; k<mx; k++)
                            dp[k] = (dp[k] + dp[k+1]) % mod;
                    }
                    else {
                        bool s = (a[j] <= a[i]);
                        mx += s;
                        for(int k=mx; k>=s; k--)
                            dp[k] = (dp[k] + dp[k-s]) % mod;
                    }
                }
                else if(j == i) {
                    mx += 1;
                    for(int k=mx; k; k--)
                        dp[k] = dp[k-1];
                    dp[0] = 0;  
                }
                else {
                    if(a[j] == -1) {
                        for(int k=1; k<mx; k++)
                            dp[k] = (dp[k] + dp[k+1]) % mod;
                    }
                    else {
                        bool s = (a[j] < a[i]);
                        mx += s;
                        for(int k=mx; k; k--)
                            dp[k] = (dp[k] + dp[k-s]) % mod;
                    }
                }
            }
            
            // for(int j=0; j<=n; j++)
            //     cout << dp[j] << ' ';
            //     cout << endl;

            for(int j=1; j<=mx; j++)
                ans = (ans + dp[j] * a[i]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
3
+1
-
+1
*/