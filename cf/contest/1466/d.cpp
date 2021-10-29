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
ll w[200100];
int deg[200100];
int q[200100], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n;
        ll ans=0;
        for(int i=1; i<=n; i++) cin >> w[i], ans += w[i], deg[i] = 0;
        int f, t;
        for(int i=1; i<n; i++) {
            cin >> f >> t;
            ++deg[f]; ++deg[t];
            if(deg[f] > 1) q[++cnt] = w[f];
            if(deg[t] > 1) q[++cnt] = w[t];
        }
        sort(q+1, q+1+cnt);
        cout << ans << ' ';
        while(cnt) {
            ans += q[cnt--];
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}