#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, m;
int a[100100], b[100100];

int main() {
    cin >> t;
    while(t--) {
        ll sum1 = 0, sum2 = 0;
        cin >> m;
        for(int i=1; i<=m; i++) cin >> a[i], sum1 += a[i];
        for(int i=1; i<=m; i++) cin >> b[i];
        ll ans = inf_ll;
        for(int i=1; i<=m; i++) {
            ans = min(ans, max(sum1-a[i], sum2));
            sum1 -= a[i];
            sum2 += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}