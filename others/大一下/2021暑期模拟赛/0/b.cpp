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
ll a[300300];
map<ll, int> e1, e2;

int main() {
    cin >> n;
    ll ans = 0;
    ll pre = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    e2[0] = 1;
    for(int i=1; i<=n; i++) {
        pre ^= a[i];
        if(i&1) {
            ++e1[pre];
            ans += e1[pre]-1;
        } else {
            ++e2[pre];
            ans += e2[pre]-1;
        }
    }
    cout << ans << endl;
    return 0;
}