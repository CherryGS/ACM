#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll a[100100];

ll cacu(ll x, ll y) {
    ll r = x%y;
    ll c = x/y;
    return (c+1)*(c+1)*r + c*c*(y-r);
}

ll check(cint x) {
    ll ans = 0;
    int pre = k;
    for(int i=1; i<=n; i++) {
        int r = (a[i]+x-1)/x;
        pre -= r;
        if(pre < 0) return 0;
        ans += cacu(a[i], r);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    ll l=1, r=0, mid;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    while(l <= r) {
        mid = (l+r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    if(check(l-1)) --l;
    if(!check(l)) ++l;
    cout << check(l) << endl;
    return 0;
}