#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[200200];
ll sum;

void sol() {
    ll x, y;
    cin >> x >> y;
    int id = lower_bound(a+1, a+1+n, x) - a;
    ll ans = max(0ll, x - a[1]) + max(0ll, -sum + y + a[1]);
    if(id >= 1 && id <= n) ans = min(ans, max(0ll, x - a[id]) + max(0ll, -sum + y + a[id]));
    if(id > 1 && id <= n) ans = min(ans, x-a[id-1] + max(0ll, -sum+y+a[id-1]));
    id = upper_bound(a+1, a+1+n, x) - a;
    if(id <= n && id >= 1) ans = min(ans, max(0ll, -sum + y + a[id]));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum += a[i];
    sort(a+1, a+1+n);
    int m;
    cin >> m;
    for(int i=1; i<=m; i++) {
        sol();
    }
    return 0;
}