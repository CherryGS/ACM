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

ll n, m, s;
ll w[200200], v[200200];
int dl[2000200], dr[200200];
ll sum[200200], val[200200];

ll check(ll x) {
    for(int i=1; i<=n; i++)
        sum[i] = sum[i-1] + (w[i] >= x);
    for(int i=1; i<=n; i++)
        val[i] = val[i-1] + v[i]*(w[i] >= x);
    ll ss = 0;
    for(int i=1; i<=m; i++)
        ss += (sum[dr[i]]-sum[dl[i]-1]) * (val[dr[i]]-val[dl[i]-1]);
    return ss;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> m >> s;
        for(int i=1; i<=n; i++)
            cin >> w[i] >> v[i];
        for(int i=1; i<=m; i++)
            cin >> dl[i] >> dr[i];
        ll l = 0, r = 0, mid;
        for(int i=1; i<=n; i++)
            r = max(r, w[i]);
        while(l < r) {
            mid = l + (r - l + 1) / 2;
            if(check(mid) >= s) l = mid;
            else r = mid - 1;
        }
        cout << min(abs(check(l)-s), abs(check(l+1)-s)) << endl;
    }
    return 0;
}