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

int n, m, C;
ll c[300300], h[300300], d[300300];
ll D[300300], H[300300];
ll mx[1000100];
ll val[1000100];

void solve(cint T) {
    cin >> n >> C;
    for(int i=1; i<=n; i++) { cin >> c[i] >> d[i] >> h[i]; }
    for(int i=1; i<=n; i++) { mx[c[i]] = max(mx[c[i]], d[i]*h[i]); }
    for(int i=1; i<=C; i++) {
        if(mx[i]) {
            for(int j=1; i*j<=C; j++) {
                val[i*j] = max(val[i*j], mx[i]*j);
            }
        }
    }
    for(int i=1; i<=C; i++) { val[i] = max(val[i], val[i-1]); }

    // for(int i=1; i<=C; i++) { cout << val[i] << ' '; }
    // cout << endl;

    cin >> m;
    ll nd, nh, now;
    for(int i=1; i<=m; i++) {
        cin >> nd >> nh;
        now = nd * nh;
        int r = upper_bound(val+1, val+1+C, now) - val;
        if(r <= C) { cout << r << '\n'; }
        else { cout << -1 << '\n'; }
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}