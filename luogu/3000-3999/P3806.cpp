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

#define ls (u<<1)
#define rs ((u<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n=10000;

int n, m;
vector<int> to[mx_n+100], w[mx_n+100];
int son[mx_n+100]; // 经过处理后的每个点的儿子个数
bool vis[mx_n+100]; // 该点是否在分治时作为子树的根
bool d[10000010];
int e[100010], cnt;

struct query {
    int x, id;
    bool ans;
    void init(int r) { cin >> x; id = r; ans = 0; }
} q[101];

void add(cint f, cint t, int co) {
    to[f].push_back(t);
    to[t].push_back(f);
    w[f].push_back(co);
    w[t].push_back(co);
}

/* 获取通过 vis 分隔的当前子树的大小 */
int get_size(cint u, cint fa) {
    int sum = 1;
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(v != fa && !vis[v]) {
            sum += get_size(v, u);
        }
    }
    return sum;
}

/* 获取通过 vis 分隔的当前子树的重心 */
int get_root(int u, int fa, int n) {
    int pre = 0, weight = 0, id = 0;
    son[u] = 1;
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(v != fa && !vis[v]) {
            id = get_root(v, u, n);
            if(id != 0) { return id; }
            son[u] += son[v];
            weight = max(weight, son[v]);
        }
    }
    pre = max(pre, n - son[u]);
    // 树的重心可能有两个，此处任取了一个
    if(pre <= n/2) { return u; }
    return 0;
}

void cacu(int u,int fa, int val) {
    if(val > q[m].x) { return; }
    for(int i=m; i>=1; i--) {
        if(q[i].x < val) { break; }
        q[i].ans |= d[q[i].x - val];
    }
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(vis[v] == 0 && v != fa) {
            cacu(v, u, val + w[u][i]);
        }
    }
}

void update(int u, int fa, int val) {
    if(val > q[m].x) { return; }
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(vis[v] == 0 && v != fa) {
            update(v, u, val + w[u][i]);
        }
    }
    d[val] = 1;
    e[++cnt] = val;
}

void clear() { while(cnt) { d[e[cnt]] = 0; --cnt; } }

void sol(cint u) {
    // cout << u << endl;
    clear();
    vis[u] = 1;
    // 计算当前节点为根的答案
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(!vis[v]) {
            cacu(v, u, w[u][i]);
            update(v, u, w[u][i]);
        }
    }
    // 向子树递归
    for(int i=0; i<to[u].size(); i++) {
        int v = to[u][i];
        if(!vis[v]) {
            sol(get_root(v, u, get_size(v, u)));
        }
    }
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    d[0] = 1;
    for(int i=1; i<=m; i++) { q[i].init(i); }
    sort(q+1, q+1+m, [](const query&a, const query&b) { return a.x < b.x; } );
    sol(get_root(1, 1, n));
    sort(q+1, q+1+m, [](const query&a, const query&b) { return a.id < b.id; } );
    for(int i=1; i<=m; i++) {
        cout << (q[i].ans == 1 ? "AYE" : "NAY") << '\n';
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