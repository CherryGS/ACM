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

int n, m, k;
int move_r[505][505];
int move_u[505][505];
ll dp[11][505][505];

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<m; j++)
            cin >> move_u[i][j];
    for(int i=1; i<n; i++)
        for(int j=1; j<=m; j++)
            cin >> move_r[i][j];
    if(k&1) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++)
                cout << -1 << ' ';
            cout << endl;
        }
        return 0;
    }
    memset(dp, 0x3f, sizeof dp);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            dp[0][i][j] = 0;
    for(int l=1; l<=k/2; l++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(i > 1) dp[l][i][j] = min(dp[l][i][j], dp[l-1][i-1][j] + move_r[i-1][j]);
                if(i < n) dp[l][i][j] = min(dp[l][i][j], dp[l-1][i+1][j] + move_r[i][j]);
                if(j > 1) dp[l][i][j] = min(dp[l][i][j], dp[l-1][i][j-1] + move_u[i][j-1]);
                if(j < m) dp[l][i][j] = min(dp[l][i][j], dp[l-1][i][j+1] + move_u[i][j]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            cout << dp[k/2][i][j] * 2 << ' ';
        cout << endl;
    }
    return 0;
}