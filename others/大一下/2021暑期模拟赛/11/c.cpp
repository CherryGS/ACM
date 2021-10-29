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

int t, n;
bool val[200200];
ll dp[200200][2];


int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> val[i], dp[i][0] = dp[i][1] = inf_int;
        dp[0][1] = inf_int;
        for(int i=1; i<=n; i++) {
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
            dp[i][1] = min(dp[i][1], dp[i-1][0]+val[i]);
            if(i > 1) {
                dp[i][0] = min(dp[i][0], dp[i-2][1]);
                dp[i][1] = min(dp[i][1], dp[i-2][0]+val[i-1]+val[i]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}