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
char a[101], b[101];
int dp[101][101];

int main() {
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof dp);
        int ans=0;
        cin >> a >> b;
        int l1 = strlen(a);
        int l2 = strlen(b);
        for(int i=0; i<l1; i++)
            for(int j=0; j<l2; j++) {
                if(a[i] == b[j]) {
                    if(i && j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                    else dp[i][j] = max(dp[i][j], 1);
                    ans = max(ans, dp[i][j]);
                    // cout << dp[i][j] << ' ' << i << ' ' << j << endl;
                }
            }
        cout << l1+l2-ans*2 << endl;
    }
    return 0;
}