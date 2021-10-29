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

int n, k;
ll a[100100];
ll ans;

bool cmp(ll x, ll y) {
    return x > y;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n, cmp);
    for(int i=1; i<=min(n, k); i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}