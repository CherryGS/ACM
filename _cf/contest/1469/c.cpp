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

int t;
int n, k;
ll h[200200];
ll dp[200200][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> h[i];
        }
        bool flag=1;
        dp[1][0] = h[1];
        dp[1][1] = h[1]+k   ;
        for(int i=1; i<n && flag; i++) {
            if(dp[i][1] <= h[i+1] || dp[i][0] >= h[i+1]+2*k-1) flag=0;
            dp[i+1][0] = max(h[i+1], dp[i][0] - k + 1);
            dp[i+1][1] = min(h[i+1]+2*k-1, dp[i][1]+k-1);
        }
        if(dp[n][0] == h[n] && flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
/*
1
6 2
2 0 0 0 3 2
*/