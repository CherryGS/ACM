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

int t;
double dp[100100];
double p;
int n;
double a[101];
int m[101];
int ans;

int main() {
    int t;
    cin >> t;
    int tt = t;
    while(t--) {
        cin >> p >> n;
        int mx = 0;
        ans = 0;
        for(int i=1; i<=n; i++) cin >> m[i] >> a[i];
        for(int i=0; i<=100*n; i++) dp[i] = 0.0;
        for(int i=1; i<=n; i++)
            for(int j=mx; j>=0; j--) {
                if((dp[j] || !j) && dp[j] < p) {
                    if(dp[j+m[i]]) dp[j+m[i]] = min(dp[j+m[i]], dp[j] + (1.0-dp[j])*a[i]);
                    else dp[j+m[i]] = dp[j] + (1.0-dp[j])*a[i];
                }
                mx = max(mx, j+m[i]);
            }
        for(int i=1; i<=mx; i++) {
            if(dp[i] && dp[i] <= p) ans = i;
        }
        printf("Case %d: %d\n", tt-t+1, ans);
    }
    return 0;
}
/*
1
0.75 3
1 0.01
2 0.25
3 0.5
*/