#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
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

int n, m;
struct edge {
    int u, v;
    int w;
    bool operator < (const edge&a) const {
        return w > a.w;
    }
    void init() {
        cin >> u >> v >> w;
    }
} r[500500];
int bcj[10010];
int sum[10010];
int h[10010], nx[20020], to[20020], w[20020], cnt;
int son[10010];
bool vis[10010];

int fd(cint x) { return bcj[x] == x ? x : bcj[x] = fd(bcj[x]); }

bool cmp(const edge&a, const edge&b) {
    return a.w < b.w;
}

void add(cint f, cint t, cint co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void ins(const edge&a) {
    int u = a.u;
    int v = a.v;
    int w = a.w;
    add(u, v, w);
    add(v, u, w);
}

ll ans;

void dfs(cint loc, cint fa, cint mx) {
    // cout << loc << " --- " << fa << " --- " << mx << endl;
    if(mx < inf_int && !vis[loc]) ans += mx;
    for(int i = h[loc]; i; i=nx[i]) {
        if(to[i] != fa) {
            dfs(to[i], loc, min(mx, w[i]));
        }
    }
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) { bcj[i] = i; sum[i] = 1; }
    for(int i=1; i<=m; i++) r[i].init();
    sort(r+1, r+1+m);
    int ss = -1;
    for(int i=1; i<=m; i++) {
        int x = fd(r[i].u), y = fd(r[i].v);
        if(sum[x] > sum[y]) swap(x, y);
        if(x != y) { bcj[x] = y; sum[y] += sum[x]; }
        if(sum[y] == n) { ss = r[i].w; break; }
    }
    vector<edge> q;
    for(int i=1; i<=m; i++) {
        if(r[i].w >= ss) q.push_back(r[i]);
        else break;
    }
    sort(q.begin(), q.end(), cmp);
    for(int i=1; i<=n; i++) { bcj[i] = i; sum[i] = 1; }
    for(auto k: q) {
        int x = fd(k.u);
        int y = fd(k.v);
        if(sum[x] > sum[y]) swap(x, y);
        if(x != y) { bcj[x] = y; sum[y] += sum[x]; ins(k); }
    }
    for(int i=1; i<=n; i++) {
        dfs(i, i, inf_int);
        vis[i] = 1;
    }
    cout << ans << endl;
    return 0;
}