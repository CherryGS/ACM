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

char a[5050], b[5050];
ll jie[10010];
int dp[5050][5050];
int l1, l2;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(cint x, cint y) {
    return (jie[x]*ksm((jie[y]*jie[x-y])%mod, mod-2)) % mod;
}

void init() {
    jie[0] = 1;
    for(int i=1; i<=10000; i++)
        jie[i] = (jie[i-1]*i) % mod;
}

void debug() {
    for(int i=0; i<=l1; i++) {
        for(int j=0; j<=l2; j++)
            cout << dp[i][j] << ' ';
            cout << endl;
    }
}

int main() {
    init();
    cin >> a >> b;
    l1 = strlen(a), l2 = strlen(b);
    // dp[0][0] = 1;
    for(int i=0; i<=5000; i++) dp[i][0] = dp[0][i] = 1;
    ll ans = 0;
    for(int i=0; i<l1; i++) {
        for(int j=0; j<l2; j++) {
            if(a[i] == b[j]) {
                dp[i+1][j+1] += dp[i][j];
            }
            if(a[i] < b[j]) {
                int x1 = l1-i-1;
                int x2 = l2-j-1;
                cout << i << " ---- " << j << " ---- " << C(x1+x2, x1)*dp[i][j] << endl;
                ans = (ans + C(x1+x2, x1)*dp[i][j]) %mod;
            }
            dp[i][j+1] += dp[i][j];
            dp[i+1][j] += dp[i][j] - 1;
        }
        // dp[i+1][0] = 1;
    }
    debug();
    cout << ans << endl;
    return 0;
}
/*
ab
abc

*/