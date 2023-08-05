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
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;
const int mod = 998244353;

int n;
int a[300200];

ll fac(int N) {
    ll ans = 1;
    for(ll i=2; i<=N; i++)
        ans = (ans*i)%mod;
    return ans;
}

ll ksm(ll x, int c) {
    ll ans = 1;
    ll tmp = x;
    while(c) {
        if(c&1) ans = (ans*tmp) % mod;
        c >>= 1;
        tmp = (tmp*tmp) % mod; 
    }
    return ans;
}

ll counter(int N) {
    return (fac(2*N)*ksm((fac(N)*fac(N))%mod, mod-2)) % mod;
}

int main() {
    cin >> n;
    for(int i=1; i<=2*n; i++) cin >> a[i];
    sort(a+1, a+1+2*n);
    ll pre = 0;
    for(int i=1; i<=n; i++)
        pre = (pre + a[n+i] - a[i]) % mod;
    cout << (pre*counter(n)) % mod;
    return 0;
}