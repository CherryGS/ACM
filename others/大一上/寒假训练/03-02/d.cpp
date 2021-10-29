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
ll dp[100100];
ll ans = 1;

int main() {
    cin >> n >> m;
    ll tmp = 0;
    dp[1] = 1;
    for(int i=2; i<=n+1; i++) {
        if(i-m > 0) tmp += dp[i-m];
        tmp %= mod;
        dp[i] = tmp;
        ans += dp[i];
        ans %= mod;
    }
    // for(int i=1; i<=n+1; i++)
    //     cout << dp[i] << ' ';
    // cout << endl;
    cout << ans << endl;
    return 0;
}