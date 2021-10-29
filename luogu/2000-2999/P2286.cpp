#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1000000;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
set<ll> x, y;

int main() {
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> n;
    ll ans=0;
    x.insert(-inf_ll/4), x.insert(inf_ll/4);
    y.insert(-inf_ll/4), y.insert(inf_ll/4);
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        if(!a) {
            if(y.size() == 2) x.insert(b);
            else {
                auto k = y.lower_bound(b);
                auto k1 = k;
                k1--;
                if(abs(*k1-b) <= abs(*k-b)) {
                    ans = (ans+abs(*k1-b)) % mod;
                    y.erase(k1);
                } else {
                    ans = (ans+abs(*k-b)) % mod;
                    y.erase(k);
                }
            }
        } else {
            if(x.size() == 2) y.insert(b);
            else {
                auto k = x.lower_bound(b);
                auto k1 = k;
                k1--;
                // cout << *k1 << ' ' << *k << ' ' << ans << endl;
                if(abs(*k1-b) <= abs(*k-b)) {
                    ans = (ans+abs(*k1-b)) % mod;
                    x.erase(k1);
                } else {
                    ans = (ans+abs(*k-b)) % mod;
                    x.erase(k);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}