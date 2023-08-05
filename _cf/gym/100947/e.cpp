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

int t, n, m;
int aa, bb;
ll to[200200];

ll ksm(ll bs, int x) {
    ll ans=1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(int x, int y) {
    return (to[x]*ksm((to[y]*to[x-y])%mod,mod-2))%mod;
}

int main() {
    to[0] = 1;
    to[1] = 1;
    for(int i=2; i<=200000; i++)
        to[i] = (to[i-1]*i) % mod;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> aa >> bb;
        cout << (C(n+m-2, n-1)%mod - (C(aa+bb-2, aa-1)*C(n+m-aa-bb, n-aa))%mod+mod)%mod << endl;
    }
    return 0;
}