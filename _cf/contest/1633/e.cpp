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

struct edge {
    int u, v;
    ll w;
};

int n, m;
ll p, k, a, b, c;
vector<edge> e;

int bcj[51];
ll now;
ll up, down;
int fd(cint x) { return bcj[x] == x ? x : bcj[x] = fd(bcj[x]); }
bool cmp(const edge&a, const edge&b) { return abs(a.w-now) < abs(b.w-now); }
auto kruskal(const ll& x) {
    now = x;
    up = down = 0;
    for(int i=1; i<=n; i++) { bcj[i] = i; }
    sort(e.begin(), e.end(), cmp);
    ll ans = 0;
    for(auto &k: e) {
        int u = fd(k.u);
        int v = fd(k.v);
        if(u != v) {
            bcj[u] = v;
            if(k.w <= now) { ++down; }
            else { ++up; }
            ans += abs(k.w - now);
        }
    }
    return ans;
}

void solve(cint T) {
    cin >> n >> m;
    int u, v;
    ll ww;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> ww;
        e.push_back({u, v, ww});
    }
    vector<ll> query;
    cin >> p >> k >> a >> b >> c;
    ll q;
    for(int i=1; i<=p; i++) {
        cin >> q;
        query.push_back(q);
    }
    for(int i=p+1; i<=k; i++) {
        q = (q*a + b) % c;
        query.push_back(q);
    }
    sort(query.begin(), query.end());
    vector<ll> pre;
    for(int i=0; i<e.size(); i++) {
        for(int j=i; j>=0; j--) {
            pre.push_back((e[i].w+e[j].w+1)/2);
        }
    }
    sort(pre.begin(), pre.end());
    ll ans = 0;
    ll now_ans = 0;
    int r = 0;
    for(int i=0; i<query.size(); i++) {
        ll &qr = query[i];
        if(i == 0) { now_ans = kruskal(qr); }
        else {
            if(r < pre.size() && qr >= pre[r]) {
                now_ans = kruskal(qr);
            }
            else {
                now_ans = now_ans + (down-up) * (qr-query[i-1]);
            }
        }
        while(r < pre.size() && qr >= pre[r]) { ++r; }
        ans ^= now_ans;
        // cout << now_ans << ' ' << up << ' ' << down << endl;
    }
    // cout << e[0].u << ' ' << e[0].v << ' ' << e[0].w << endl;
    cout << ans << '\n';
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