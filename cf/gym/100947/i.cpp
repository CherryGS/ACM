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
int a[10100];
int b[1001000];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        memset(b, 0, sizeof b);
        ll ans=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sqrt(a[i]); j++) if(!(a[i]%j)){
                ans += b[j];
                if(j != a[i]/j) ans += b[a[i]/j];
            }
            ++b[a[i]];
        }
        cout << ans << endl;
    }
    return 0;
}