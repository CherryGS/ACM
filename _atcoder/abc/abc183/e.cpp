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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int h, w;
char mp[2020][2020];
ll sum[2020][2020][3];
// 0  →; 1  ↑; 2  ↘
ll dp[2020][2020];


int main() {
    cin >> h >> w;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) {
            cin >> mp[i][j];
        }
    dp[1][1] = 1;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) if(mp[i][j] != '#'){
            dp[i][j] += (sum[i-1][j][0] + sum[i][j-1][1] + sum[i-1][j-1][2]) % mod;
            sum[i][j][0] = (sum[i-1][j][0] + dp[i][j]) % mod;
            sum[i][j][1] = (sum[i][j-1][1] + dp[i][j]) % mod;
            sum[i][j][2] = (sum[i-1][j-1][2] + dp[i][j]) % mod;
        }
    // for(int i=1; i<=h; i++) {
    //     for(int j=1; j<=w; j++)
    //         cout << dp[i][j] << ' ';
    //         cout << endl;
    // }
    cout << dp[h][w] << endl;
    return 0;
}