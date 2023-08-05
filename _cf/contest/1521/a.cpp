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

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    int t;
    ll a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll mn = a*b;
        if(b == 2) mn += a;
        if(b == 1) cout << "NO" << endl;
        else cout << "YES" << endl << a << ' ' << mn - a << ' ' << mn << endl;
    }
    return 0;
}