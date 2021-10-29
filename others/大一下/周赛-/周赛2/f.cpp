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

int t;
int n, m;
int r1, r2, c1, c2;
ll to[201000];
ll ans1=0;

ll ksm(ll bs, int x) {
    ll ans=1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

ll C(ll x, ll y) {
    return (to[x]*ksm((to[y]*to[x-y])%mod, mod-2))%mod;
}

int main() {
    ios::sync_with_stdio(false);
    to[0] = 1;
    for(int i=1; i<=200000; i++) to[i] = (to[i-1]*(ll)i) % mod;
    cin >> t;
    while(t--) {
        ans1 = 0;
        cin >> n >> m;
        cin >> r1 >> c1 >> r2 >> c2;
        for(int i=r1+1; i<=r2; i++)
            ans1 = (ans1 + ((C(i+c1-2, c1-1)-C(i+c1-3, c1-1)+mod))%mod *C(m+n-i-c1, m-c1)) % mod;
        for(int i=c1+1; i<=c2; i++)
            ans1 = (ans1 + ((C(i+r1-2, r1-1)-C(i+r1-3, r1-1)+mod))%mod *C(m+n-i-r1, n-r1)) % mod;
        ans1 = (ans1 + (C(r1+c1-2, r1-1)*C(n+m-r1-c1, n-r1))%mod ) % mod;
        ll tmp = C(n+m-2, n-1);
        cout << ((tmp-ans1+mod)%mod * ksm(tmp, mod-2)) % mod << endl;
    }
    return 0;
}