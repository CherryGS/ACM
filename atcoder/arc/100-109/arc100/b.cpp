#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n;
ll a[200200];

ll max_(ll* arr, cint nn) {
    sort(arr, arr+nn);
    return arr[nn-1] - arr[0];
}

ll cacu(cint x1, cint x2, cint x3) {
    ll arr[4];
    arr[0] = a[x1];
    arr[1] = a[x2] - a[x1];
    arr[2] = a[x3] - a[x2];
    arr[3] = a[n] - a[x3];
    return max_(arr, 4);
}

ll sol(cint loc1) {
    int x = lower_bound(a+1, a+loc1+1, (a[loc1]+1)/2) - a;
    int y = lower_bound(a+loc1+2, a+n+1, (a[n]+a[loc1+1]+1)/2) - a;
    if(x == loc1) --x;
    if(y == n) --y;
    ll ans = cacu(x, loc1, y);
    if(x != 1) ans = min(ans, cacu(x-1, loc1, y));
    if(y != loc1+1) ans = min(ans, cacu(x, loc1, y-1));
    cout << x << "  " << loc1 << "  " << y << endl;
    return ans;
}

int main() {
    ll t;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t;
        a[i] = a[i-1] + t;
    }

    ll ans = a[n];
    for(int i=2; i<n-1; i++) ans = min(ans, sol(i));
    cout << ans;

    return 0;
}