#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
ll a[100100];
ll ans[100100];

void check() {
    ll sum = 0;
    for(int i=1; i<=n; i++) sum += a[i] * ans[i];
    cout << sum << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) ans[i] = 0;
        if(!(n&1)) {
            for(int i=1; i<=n; i++) {
                if(i <= n/2) ans[n-i+1] = a[i];
                else ans[n-i+1] = -a[i];
            }
        }
        else {
            for(int i=1; i<=n-1; i++) {
                if(i <= (n-1)/2) ans[n-i] = a[i];
                else ans[n-i] = -a[i];
            }
            ans[n] += a[1];
            ans[1] += -a[n];
            while(ans[1] == 0 || ans[2] == 0) {
                ans[n] += a[1];
                ans[1] += -a[n];
            }
        }
        // check();
        for(int i=1; i<=n; i++) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}