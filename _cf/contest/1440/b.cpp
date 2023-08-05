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

int t, n, k;
ll a[1010000];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n*k; i++) cin >> a[i];
        ll ans = 0, loc = n*k;
        for(int i=1, cnt; i<=k; i++) {
            cnt=0;
            while(cnt<n/2) {
                ++cnt;
                --loc;
            }
            // cout << a[loc] << ' ';
            ans += a[loc];
            --loc;
        }
        cout << endl;
        cout << ans << endl;
    }    
    return 0;
}