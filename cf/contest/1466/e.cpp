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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, mx;
ll num[62];
ll a[500500];

void deal(ll x) {
    int cnt=0;
    while(x) {
        if(x&1) ++num[cnt];
        x >>= 1;
        ++cnt;
    }
    mx = max(mx, cnt);
}

inline ll sol_1(ll x) {
    int cnt=0;
    ll tmp = 0;
    while(x && cnt <= mx) {
        if(x&1) {
            tmp = (tmp + ((1ll<<cnt)%mod*num[cnt]) % mod)%mod;
        }
        x >>= 1;
        ++cnt;
    }
    return tmp;
}

inline sol_2(ll x) {
    int cnt=0;
    ll tmp = 0;
    while(cnt <= mx) {
        if(x&1) {
            tmp = (tmp + ((1ll<<cnt)%mod*n)%mod)%mod;
        } else tmp = (tmp + ((1ll<<cnt)%mod*num[cnt]) % mod)%mod;
        x >>= 1;
        ++cnt;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    ll t1, t2, ans;
    while(t--) {
        memset(num, 0, sizeof num);
        ans = mx = 0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i], deal(a[i]);
        for(int i=1; i<=n; i++) {
            t1 = sol_1(a[i]);
            t2 = sol_2(a[i]);
            ans = (ans + (t1*t2)%mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}