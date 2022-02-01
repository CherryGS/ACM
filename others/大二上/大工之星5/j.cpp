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

int n;
ll e; // 1e9
ll x[202], y[202], r[202];
int bcj[202];

int fd(int x) { return bcj[x] == x ? x : bcj[x] = fd(bcj[x]); }

ll cacu(int s, int t) {
    if(s == t) return 0;
    if(s == 0) {
        if(t == n+1) return inf_ll;
        return max(0ll, x[t] - r[t]);
    }
    if(t == n+1) {
        return max(0ll, abs(e-x[s])-r[s]);
    }
    return ceil(((sqrt(pow(x[s]-x[t], 2ll)+pow(y[s]-y[t], 2ll))) - r[s] - r[t])/2.0);
}

struct node {
    int x, y;
    ll z;
    bool operator <(const node&a) const {
        return z < a.z;
    }
};

void solve(cint T) {
    cin >> n >> e;
    if(e == 0) { cout << 0 << endl; return; }
    vector<node> q;
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i] >> r[i];
    for(int i=0; i<=n+1; i++) bcj[i] = i;
    for(int i=0; i<=n+1; i++) {
        for(int j=i+1; j<=n+1; j++) {
            q.push_back({i, j, cacu(i, j)});
        }
    }
    ll ans = inf_ll;
    sort(q.begin(), q.end());
    // for(auto k: q)
    //     cout << k.x << " " << k.y << ' ' << k.z << endl;
    for(auto k: q) {
        int u = fd(k.x);
        int v = fd(k.y);
        if(u != v) bcj[u] = v;
        if(fd(0) == fd(n+1)) { ans = k.z; break; }
    }
    if(ans == inf_ll) cout << "Impossible" << endl;
    else cout << ans << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}