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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[300200];
map<ll, int> e;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        if(i&1) a[i] = a[i-1] + a[i];
        else a[i] = a[i-1] - a[i];
        ++ e[a[i]];
    }
    ++ e[0];
    ll ans = 0;
    for(auto k=e.begin(); k!=e.end(); ++k) {
        ll r = k->second;
        // cout << r << "----" << endl;
        ans += r*(r-1)/2;
    }
    cout << ans << endl;
    return 0;
}
/*
5
1 1 1 1 1
*/