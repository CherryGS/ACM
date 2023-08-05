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

int n;
ll to[200200];
ll dp[200200];

ll ksm(ll bs, int x) {
    ll ans=1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    to[0] = 1;
    cin >> n;
    for(int i=1; i<=n; i++) to[i] = (to[i-1]*2) % mod;
    dp[0]=1, dp[1]=1, dp[2]=1;
    ll odd=1, eve=2;
    for(int i=3; i<=n; i++) {
        if(i&1) {
            dp[i] = eve;
            odd = (eve+odd) % mod;
        } else {
            dp[i] = odd;
            eve = (eve+odd) % mod;
        }
    }
    cout << (dp[n]*ksm(to[n], mod-2)) % mod;
    return 0;
}