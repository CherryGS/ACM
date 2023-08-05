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

ll n, m;
ll dp[404][404];
ll pre[404];
ll jie[404];
ll pro[404][404];

void init() {
    pre[0] = 1;
    for(int i=1; i<=400; i++)
        pre[i] = (pre[i-1]*2) % m;

    jie[0] = 1;
    for(int i=1; i<=400; i++)
        jie[i] = (jie[i-1]*i) % m;
    
    for(int i=1; i<=n; i++) pro[0][i] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=j; k++) {
                pro[i][j] += pro[i-1][k];
                pro[i][j] %= m;
            }
        }
    }
    // cout << pro[2][3] << ' ' << pro[2][4] << endl;
}

int main() {
    cin >> n >> m;
    init();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(j == 1) dp[i][j] = pre[i-1];
            else {
                for(int k=i-2; k>=1; k--) {
                    if(dp[k][j-1]) {
                        int r = i-k-1;
                        dp[i][j] += ((dp[k][j-1] * pro[r][i-r-j+2])%m * pre[r-1]) % m;
                        dp[i][j] %= m;
                        // cout << r << "-----" << i-r-j+2 << " " << i << ' ' << j << ' ' << k << ' ' << pro[r][i-r-j+2] << ' ' << dp[i][j] << endl; 
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        // cout << i << "---" << dp[n][i] << endl;
        ans = (ans + dp[n][i]) % m;
    }
    cout << ans << endl;
    return 0;
}
/*
6 10000007
400 10000007
*/