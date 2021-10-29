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

int t;
ll p, q;

ll sol(ll div) {
    if(div==1) return 1;
    // cout << div << endl;
    ll tmp =  p/q;
    while(!(tmp%div)) tmp /= div;
    return tmp*q/div;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> p >> q;
        ll ans = 0;
        if(p%q) {cout << p << endl; continue;}
        else for(ll i = 1; i <= (int)sqrt(q)+1; i++)
            if(!(q%i)) {
                ans = max(ans, max(sol(i), sol(q/i)));
            }
        if(!ans) ans = p/q;
        cout << ans << endl;
    }
    return 0;
}