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

int n, m;
set<pii> e;
int a[100100];

ll cacu(int l, int r) {
    return 1ll * l * (n-r+1) + 1ll*(r+l)*(r-l+1)/2 - 2;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int lst = 1;
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] != a[lst] || i == n) {
            ans += cacu(lst, i);
            e.insert({lst, i-1});
            lst = i;
        }
    }
    int x, v;
    for(int i=1; i<=m; i++) {
        cin >> x >> v;
        if(v == a[x]) {
            cout << ans << '\n';
            continue;
        }
        auto k = e.upper_bound({x, inf_int});
        --k;
        auto r = *k;
        e.erase(k);
        ans -= cacu(r.first, r.second);
        if(r.first < x) { e.insert({r.first, x-1}); ans += cacu(r.first, x-1); }
        if(r.second > x) { e.insert({x+1, r.second}); }
        e.insert({x, x});

    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}