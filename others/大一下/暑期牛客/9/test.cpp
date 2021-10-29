#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    ll q;
    for(ll i=1; i<=10000000; i++) {
        q = (mod + 1 - ksm(i, mod-2)) % mod;
        assert(((i-1)*ksm(i, mod-2))%mod == q);
        if(((i-1)*ksm(i, mod-2))%mod == q) {}
        else cout << "1" << endl;
    }
    return 0;
}