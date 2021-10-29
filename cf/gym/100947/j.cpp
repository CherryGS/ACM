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

int t, n, p, q;
int a[2020];
int dp[2020][2020];

bool check(cint key) {
    memset(dp, -1, sizeof dp);
    dp[0][p] = q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=p; j++) if(dp[i][j] >= 0){
            int k = upper_bound(a+1, a+n+1, a[i+1]+key-1) - a;
            k--;
            if(j) dp[k][j-1] = max(dp[k][j-1], dp[i][j]);
            k = upper_bound(a+1, a+n+1, a[i+1]+2*key-1) - a;
            k--;
            if(dp[i][j]) dp[k][j] = max(dp[k][j], dp[i][j]-1);
        }
    }
    // cout << key << endl;
    // for(int i=1; i<=n; i++) {
    //     cout << "i:" << i << "  ";
    //     for(int j=0; j<=p; j++)
    //         cout << dp[i][j] << ' ';
        // cout << endl;
    // }
    // cout << endl;
    for(int i=0; i<=p; i++)
        if(dp[n][i] >= 0) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> p >> q;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        if(p+q >= n) {cout << 1 << endl; continue;}
        int l=1, r=1e9, mid;
        while(l <= r) {
            mid = (l+r) >> 1;
            if(check(mid)) r = mid-1;
            else l = mid+1;
        }
        if(check(mid)) cout << mid << endl;
        else cout << mid+1 << endl;
    }
    return 0;
}