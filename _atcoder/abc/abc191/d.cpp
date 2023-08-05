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

double x, y, r;

int main() {
    cin >> x >> y >> r;
    ll a1 = (x/abs(x))*((ll)(abs((ll)(x+r))));
    ll a2 = (x/abs(x))*((ll)(abs((ll)(x-r))+0.5));
    ll ans=0;
    // cout << a1 << ' ' << a2 << endl;
    for(int i=a2; i<=a1; i++) {
        double dy = sqrt(r*r - pow(x-i, 2));
        // cout << y+dy << ' ' << y-dy << ' ' << dy << endl;
        // cout << abs(int(y+dy) - int(y-dy+0.999)) << endl;
        ans += abs((ll)(y+dy) - (ll)(y-dy+0.999)) + 1;
    }
    cout << ans << endl;
    return 0;
}