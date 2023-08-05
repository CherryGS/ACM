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

int dp[1<<17][20];

int x[20], y[20], z[20];
int n;

int dis(cint a, cint b) {
    return abs(x[b]-x[a]) + abs(y[b]-y[a]) + max(0, z[b]-z[a]);
}

int main() {
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    dp[0][1] = 0;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> z[i];
    for(int j = 1; j < n; j++)
        dp[1<<j][j+1] = dis(1, j+1); 
    cout << dis(1,2) << ' ' << dis(2,3) << ' ' << dis(3, 1) << endl;
    for(int i = 1; i < (1<<n); i <<= 1, i += 1) {
        for(int m = i; m < (1<<n); m <<= 1) {
            for(int j = 1; j < n; j++)
                if(m&(1<<j)) for(int k = 0; k < n; k++) if(j != k)
                    dp[m|(1<<k)][k+1] = min(dp[m|(1<<k)][k+1], dp[m][j+1] + dis(j+1, k+1));
        }
    }
    cout << dp[(1<<n)-1][1];
    return 0;
}