#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[200200];

int main() {
    cin >> n;
    ll now=0, mx=0, dp=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
        dp = max(dp, a[i]);
        if(now+dp>mx) mx = now+dp;
        now += a[i];
        if(now > mx) mx = now;
    }
    cout << mx;
    return 0;
}