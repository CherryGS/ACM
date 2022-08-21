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
int v[101];
vector<int> cdn, user;

const int mxn = 101; // 最大点数
const int mxm = 100002; // 最大边数
struct dinic {
    int s, t; // 源，汇
    int w[mxm*2];
    int h[mxn], nx[mxm*2], to[mxm*2], cnt=1; // 链式前向星, cnt=1 方便找到反边
    int cur[mxn]; // 当前弧优化辅助数组
    int label[mxn]; // 分层图标号
    void clear_map() { cnt = 1; for(int i=1; i<=mxn; i++) { h[i] = 0; } }
    void add(cint f, cint t, cint co) {
        nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt] = co;
        nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt] = 0;
    }
    bool bfs() {
        memset(label, 0x3f, sizeof label); // 初始化标号
        memcpy(cur, h, sizeof h); // 当前弧优化
        queue<int> q;
        q.push(s);
        label[s] = 0;
        while(!q.empty()) {
            int r = q.front();
            q.pop();
            for(int i=h[r]; i; i=nx[i])
                if(w[i] && label[to[i]] > label[r]+1) {
                    label[to[i]] = label[r] + 1;
                    q.push(to[i]);
                }
        }
        return label[t] < label[mxn-1];
    }
    int dfs(cint loc, int cap) {
        if(loc == t) return cap;
        int sum = 0;
        for(int i=cur[loc]; i; i=nx[i]) {
            cur[loc] = i;
            if(label[to[i]] == label[loc] + 1) {
                int d = dfs(to[i], min(cap, w[i]));
                if(d) { w[i] -= d; w[i^1] += d; cap -= d; sum += d; }
                if(!cap) break;
            }
        }
        return sum;
    }
    int max_flow(cint s, cint t) {
        this->s = s;
        this->t = t;
        int flow = 0;
        while(bfs()) { flow += dfs(s, inf_int); }
        return flow;
    }
} A;

struct edge {
    int u, v, c;
    void init() { cin >> u >> v >> c; }
} a[202];

bool check(int x, int lim) {
    A.clear_map();
    int sum = user.size();
    for(auto &v: user) { A.add(v, n+1, 1); }
    for(int i=1; i<=m; i++) { A.add(a[i].u, a[i].v, a[i].c/x); }
    for(int i=0; i<cdn.size(); i++) {
        if((lim>>i)&1) {
            // cout << i << ' ' << cdn[i] << ' ' << lim << endl;
            A.add(1, n+i+2, inf_int);
            for(int j=A.h[cdn[i]]; j; j=A.nx[j]) {
                if(A.w[j] == 0) { continue; }
                A.add(n+i+2, A.to[j], A.w[j]);
                A.w[j] = 0;
            }
            ++sum;
            A.add(cdn[i], n+1, 1);
        }
    }
    int res = A.max_flow(1, n+1);
    // if(lim == 1) {
    //     cout << res << ' ' << sum << ' ' << x << endl;
    // }
    return res == sum;
}

void solve(cint T) {
    cdn.clear();
    user.clear();
    cin >> n >> m;
    for(int i=2; i<=n; i++) { cin >> v[i]; }
    for(int i=2; i<=n; i++) { if(v[i] == 1) { cdn.push_back(i); } else if(v[i] == 2) { user.push_back(i); } }
    // cout << user.size() << ' ' << cdn.size() << endl;
    for(int i=1; i<=m; i++) { a[i].init(); }
    int ans = 0;
    for(int lim=0; lim < (1<<cdn.size()); lim++) {
        int l = 0, r = 1e6, mid;
        while(l < r) {
            mid = l + ((r-l+1)>>1);
            if(check(mid, lim)) { l = mid; }
            else { r = mid - 1; }
        }
        // cout << lim << ' ' << l << endl;
        ans = max(ans, l);
    }
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}