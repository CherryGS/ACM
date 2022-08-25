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
char s[404][404];

const int mxn = 400*2+2; // 最大点数
const int mxm = 400*400*2+400*2; // 最大边数
struct dinic {
    int s, t; // 源，汇
    bool vis[mxn+10];
    ll dis[mxn+10];
    ll w[mxm*2+10], c[mxm*2+10];
    int h[mxn+10], nx[mxm*2+10], to[mxm*2+10], cnt=1; // 链式前向星, cnt=1 方便找到反边
    int cur[mxn+10]; // 当前弧优化辅助数组
    void clear_map() { cnt = 1; for(int i=1; i<=mxn; i++) h[i] = 0; }
    void add(int f, int t, int co, int ca) {
        nx[++cnt] = h[f]; h[f] = cnt; to[cnt] = t; w[cnt] = co; c[cnt] = ca;
        nx[++cnt] = h[t]; h[t] = cnt; to[cnt] = f; w[cnt] = -co; c[cnt] = 0;
    }
    bool spfa() {
        memcpy(cur, h, sizeof h); // 当前弧优化
        memset(dis, 0x3f, sizeof dis);
        queue<int> q; q.push(s);
        dis[s] = 0; vis[s] = 1;
        int v;
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            for(int i=h[u]; i; i=nx[i]) {
                v = to[i];
                if(c[i] && dis[v] > dis[u] + w[i]) {
                    dis[v] = dis[u] + w[i];
                    if(!vis[v]) { q.push(v); vis[v] = 1; }
                }
            }
        }
        return dis[t] < hf_int;
    }
    ll dfs(cint u, ll cap, ll &val) {
        if(u == t) { return cap; }
        ll sum = 0; int v; vis[u] = 1;
        for(int i=cur[u]; i; i=nx[i]) {
            cur[u] = i; v = to[i];
            if(c[i] > 0 && !vis[v] && dis[v] == dis[u] + w[i]) {
                ll d = dfs(v, min(cap, c[i]), val);
                if(d) { c[i] -= d; c[i^1] += d; cap -= d; sum += d; val += 1ll * d * w[i]; }
                if(cap == 0) { break; }
            }
        }
        vis[u] = 0;
        return sum;
    }
    pair<ll, ll> max_flow(int s, int t) {
        this->s = s;
        this->t = t;
        ll flow = 0, res = 0;
        while(spfa()) { flow += dfs(s, inf_int, res); }
        return {flow, res};
    }
    void pr() {
        vector<int> ans;
        for(int i=1; i<=n; i++) {
            for(int j=h[i]; j; j=nx[j]) {
                if(to[j] > n && to[j] < n+m+1 && c[j] == 0) {
                    ans.push_back(to[j]);
                    break;
                }
            }
        }
        for(auto &k: ans) { cout << k-n << ' '; } 
        cout << '\n';
    }
} A;

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> s[i]; }
    for(int i=1; i<=n; i++) {
        A.add(n+m+1, i, 0, 1);
        for(int j=0; j<m; j++) {
            if(s[i][j] == '1') { A.add(i, n+j+1, 0, 1); }
        }
    }
    for(int i=1; i<=m; i++) {
        for(int j=0; j<n; j++) { A.add(n+i, n+m+2, j+1, 1); }
    }
    auto res = A.max_flow(n+m+1, n+m+2);
    if(res.first < n) { cout << -1 << '\n'; }
    else { A.pr(); }
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