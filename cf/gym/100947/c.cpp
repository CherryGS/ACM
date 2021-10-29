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

int t, n;
ll a[10100];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum=0, tmp=0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            sum += a[i];
            if(i&1) tmp+=a[i];
        }
        ll ans=tmp;
        if(n&1) {
            for(int i=1; i<n; i++) {
                tmp = sum - tmp + a[i];
                ans = max(ans, tmp);
            }
            cout << ans << endl;
        } else {
            cout << max(tmp, sum-tmp) << endl;
        }
    }
    return 0;
}