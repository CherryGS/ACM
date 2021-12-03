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

int n, m, k;
int a[1000100];
int bcj[500500];

struct edge {
    int u, v, w, e;
    void init() {
        cin >> u >> v >> w >> e;
    }
    bool operator < (const edge&a) const {
        return w == a.w ? e < a.e : w < a.w;
    }
} e[1000100];

int fd(cint x) { return bcj[x] == x ? x : bcj[x] = fd(bcj[x]); }

void solve(cint T) {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=k; i++) cin >> a[i];
    for(int i=1; i<=m; i++) e[i].init();
    sort(e+1, e+1+m);
    ll ans = 0, anss = 0;
    int r = 1;
    for(int i=1; i<=m; i++) {
        int u = fd(e[i].u);
        int v = fd(e[i].v);
        if(u != v) {
            ans += e[i].w;
            while(r <= k && r <= e[i].e) {
                anss += a[r];
                ++r;
            }
        }
        bcj[u] = v;
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) cnt += bcj[i] == i;
    if(cnt > 1) cout << -1 << endl;
    else cout << ans << ' ' << anss << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}