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

ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = 0;
        for(ll i=1; i<=9; i++) {
            ll s = i;
            while(s <= n) {
                ++ans;
                s = s*10+i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}