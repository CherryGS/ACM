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

int n, m;
ll a[200200];
ll sum[200200];
ll num[200200];

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> num[i];
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++)
        if(i!=1) sum[i] = sum[i-2] + a[i];
        else sum[i] = a[i];
    ll ans = 0x7fffffffffffffff;
    for(int i=1; i<=m; i++) {
        int key = lower_bound(a+1, a+1+n, num[i]) - a - 1;
        int t = key-1;
        if(t<0) t=0;
        if((n-key)%2) {
            ans = min(ans, sum[n]-sum[t] + sum[key] - num[i]-sum[t]-sum[n-1]+sum[key]);
        } else {
            ans = min(ans, sum[n]-sum[key]-sum[n-1]+sum[t] + num[i] - sum[key] + sum[t]);
        }
    }
    cout << ans;
    return 0;
}