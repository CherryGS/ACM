#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
ll a[100100], b[100100];

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    int TT = t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int j=1; j<=m; j++) cin >> b[j];
        int l = 1, r = 1;
        ll ans = 0;
        cout << "Case " << TT-t << ": ";
        while(l <= n || r <= m) {
            if(ld(a[l])/l > ld(b[r])/r && l <= n) { ans += a[l]*(l+r-1); ++l; }
            else if(r <= m){ ans += b[r]*(l+r-1); ++r; }
        }
        cout << ans << endl;
    }
    return 0;
}
/*

*/