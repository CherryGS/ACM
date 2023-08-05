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

int t, n, m;

int main() {
    cin >> t;
    while(t--) {
        int ans=0, mn=-inf_int, cnt=0, a, mx=inf_int;
        bool key=0;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                cin >> a;
                ans += abs(a);
                if(a<0) {
                    mn = max(mn, a);
                    ++cnt;
                } 
                else if(a==0) key=1;
                else mx = min(mx, a);
            }
        if(mx+mn<0) mn = -mx;
        if(cnt&1 && !key) cout << ans + 2*mn << endl;
        else cout << ans << endl;   
    }
    return 0;
}