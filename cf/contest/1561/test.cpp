#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll x = (ll)2e5;

int main() {
    ll ans = 0;
    for(ll j=x/2; j<=x; j++) {
        for(ll i=2; i<=j; i++)
            if(j/i != j/(i-1)) ++ans;
        // cout << j << endl;
    }
        cout << ans << endl;
    cout << endl;
    return 0;
}