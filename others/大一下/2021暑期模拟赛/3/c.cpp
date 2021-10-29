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

int n, m;
ll a[200200], b[200200];

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
    if(n == 1) {
        for(int i=1; i<=m; i++) cout << a[1]+b[i] << endl;
    }else {
        sort(a+1, a+1+n);
        ll pre = a[2]-a[1];
        for(int i=3; i<=n; i++) pre = gcd(pre, a[i]-a[1]);
        for(int i=1; i<=m; i++)
            cout << gcd(a[1]+b[i], pre) << endl;
    }

    return 0;
}