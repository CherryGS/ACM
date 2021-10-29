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

ll n;
ll x, m;
int mp[100100];
ll sum[100100];

void sol(int s, cint e, ll loc, ll ans_2) {
    ll res = n-loc+1;
    int le=0;
    while(s != e) {
        sum[le+1] = sum[le] + s;
        s = mp[s];
        ++le;
    }
    sum[le+1] = sum[le] + e;
    ++le;
    ll ans_1 = sum[le] * (res/le);
    int k = res%le;
    ll ans_3 = sum[le] - sum[le-k];
    // cout << ans_1 << " " << ans_2 << " " << ans_3 << " " << k << " " << res << " " << le << endl;
    cout << ans_1 + ans_2 + ans_3;
}

int main() {
    cin >> n >> x >> m;
    int la = 0;
    ll tmp = x;
    n--;
    for(ll i=1; i<=n+1; i++) {
        x = (x*x) % m;
        if(!x || i == n+1) {
            // cout << "___" << endl;
            cout << tmp;
            break;
        }
        if(!mp[x]) {
            mp[x] = la;
            la = x;
            tmp += x;
        } else {
            // cout << "---" << i << endl;
            sol(la, (int)x, i, tmp);
            break;
        }
    }
    return 0;
}