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

ll q;
ll n;
bool flag;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> q;
    while(q--) {
        cin >> n;
        ll ans = 0;
        for(int i=1; i<n; i++)
            ans = max(ans, gcd(n^i, n&i));
        cout << ans << endl;
    }
    return 0;
}