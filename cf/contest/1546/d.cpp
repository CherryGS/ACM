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

int t, n;
char s[100100];
ll jie[100100];

void init() {
    jie[0] = 1;
    for(int i=1; i<=100000; i++)
        jie[i] = (jie[i-1]*i) % mod;
}

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

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int n1 = 0, n2 = 0;
        bool st = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') ++ n2, st = 0;
            else {
                if(st) ++n1, st = 0;
                else st = 1;
            }
        }
        // cout << n1 << ' ' << n2 << ' ' << jie[n1+n2] << ' ' << jie[n2] << endl;
        cout << C(n1+n2, n1) << endl;
    }
    return 0;
}