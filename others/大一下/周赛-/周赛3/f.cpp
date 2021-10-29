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

ll n;

int main() {
    cin >> n;
    ll ans=0;
    if(n==0) {cout << 1 << endl; return 0;}
    for(ll i=1; i<=sqrt(n); i++) {
        ans += (n/i);
    }
    ans *= 2;
    ans += 2*n+1ll;
    ans -= (ll)(sqrt(n))*(ll)sqrt(n);
    cout << ans << endl;
    return 0;
}