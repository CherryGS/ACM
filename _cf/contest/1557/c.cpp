#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const ll mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll t, n, k;

ll ksm(ll bs, ll x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll ans = 1, pre = 0;
        for(ll i=1; i<=k; i++) {
            if(n&1) {
                ans = (ans*(1+ksm(2, n-1))) % mod;
            }
            else {
                // cout << ksm(2, n*(k-i) % mod) << endl;
                pre = (pre + (ans*ksm(2, n*(k-i)%(mod-1)))%mod) % mod;
                ans = (ans*((ksm(2, n-1)-1+mod)%mod)) % mod;
            }
            // cout << ans << ' '<< pre << endl;
        }
        cout << (ans+pre) % mod << endl;
    }
    return 0;
}