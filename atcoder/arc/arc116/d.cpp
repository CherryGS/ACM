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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int pre[14], l;
ll dp[14][5050];
ll jie[5050];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

void debug() {
    for(int i=0; i<=l; i++) {
        for(int j=0; j<=m; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
}

void init() {
    jie[0] = 1;
    for(int i=1; i<=5000; i++)
        jie[i] = (jie[i-1]*i) % mod;
}

ll C(cint x, cint y) {
    return (jie[x]*ksm((jie[y]*jie[x-y]) % mod, mod-2)) % mod;
}

int main() {
    init();
    cin >> n >> m;
    int mm = m;
    while(mm) {
        int r = mm&1;
        ++l;
        pre[l] = (r << (l-1)) + pre[l-1];
        mm >>= 1;
    }
    // cout << l << endl;
    // for(int i=0; i<=l; i++) cout << pre[i] << ' ';
    // cout << endl;
    int mx = 0;
    dp[0][0] = 1;
    for(int i=0; i<l; i++) {
        int bs = pre[i];
        int r = 1<<i;
        for(int j=bs; j<=m; j+=r) if(dp[i][j]){
            int k = (j&r) ^ (m&r);
            if(k) continue;
            for(k; j+k*r<=m && k<=n; k+=2) {
                dp[i+1][j+k*r] += (dp[i][j] * C(n, k)) % mod;
                dp[i+1][j+k*r] %= mod;
            }
        }
    }
    // debug();
    cout << dp[l][m] << endl;
    return 0;
}