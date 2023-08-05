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

int t, n;
ll a[200100];
ll mn, mx;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> mn >> mx;
        ll ans = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) {
            int s1 = lower_bound(a+1, a+1+n, mn-a[i])-a;
            int s2 = upper_bound(a+1, a+1+n, mx-a[i])-a;
            if(s1 <= i) s1 = i+1;
            if(s2 <= i) s2 = i+1;
            // cout << s1 << ' ' << s2 << endl;
            ans += s2-s1;
        }
        cout << ans << endl;
    }
    return 0;
}