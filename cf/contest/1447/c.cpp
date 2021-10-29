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
ll w;
int q[200200], cnt;

struct stu {
    ll x;
    int id;
    void init(cint i) {
        cin >> x;
        id = i;
    }
    bool operator < (const stu&a) const {return x < a.x;}
}a[200200];


int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n >> w;
        for(int i=1; i<=n; i++) a[i].init(i);
        sort(a+1, a+1+n);
        stu tt = {(w+1ll)/2ll, 0};
        int k = lower_bound(a+1, a+1+n, tt) - a;
        if(a[k].x <= w && k <= n) {
            cout << 1 << endl;
            cout << a[k].id << endl;
            continue;
        }

        --k;
        ll tmp=0;
        bool st=0;
        while(k) {
            tmp += a[k].x;
            q[++cnt] = a[k].id;
            if(tmp >= (w+1ll)/2ll) {
                st=1;
                cout << cnt << endl;
                while(cnt) {cout << q[cnt--] << ' ';}
                cout << endl;
                break;
            }
            k--;
        }
        if(!st) cout << -1 << endl;
    }
    return 0;
}