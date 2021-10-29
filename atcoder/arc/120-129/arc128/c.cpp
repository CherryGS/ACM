#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n;
ld m, s;
ld a[5050];

int main() {
    freopen("1.in", "r", stdin);
    cout.flags(ios::fixed);
    cout.precision(8);
    cin >> n >> m >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=n-1; i>=1; i--) a[i] += a[i+1];
    ld ans = 0;
    for(int i=1; i<=n; i++) {
        if(s/(n-i+1) <= m) ans = max(ans, s/(n-i+1)*a[i]);
        for(int j=i+1; j<=n; j++) {
            ld xj = (s-m*(n-i+1))/ld(i-j);
            if(xj < 0 || xj > m) break;
            ans = max(ans, xj*a[j]+(m-xj)*a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}