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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int N;
int a[2002];
int p, m, f, n, s;

const int mxn = 4002; // 最大点数
const int mxm = 12000; // 最大边数
struct dinic {
    int s, t; // 源，汇
    bool vis[mxn+10];
    ll dis[mxn+10];
    ll w[mxm*2+10], c[mxm*2+10];
    int h[mxn+10], nx[mxm*2+10], to[mxm*2+10], cnt=1; // 链式前向星, cnt=1 方便找到反边
    int cur[mxn+10]; // 当前弧优化辅助数组
    void clear_map() { cnt = 1; for(int i=1; i<=mxn; i++) h[i] = 0; }
    void add(int f, int t, int co, ll ca) {
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
        return dis[t] < dis[0];
    }
    ll dfs(cint u, ll cap, ll &val) {
        if(u == t) { return cap; }
        ll sum = 0; int v; vis[u] = 1;
        for(int i=cur[u]; i; i=nx[i]) {
            cur[u] = i; v = to[i];
            if(c[i] > 0 && !vis[v] && dis[v] == dis[u] + w[i]) {
                ll d = dfs(v, min(cap, c[i]), val);
                if(d) { c[i] -= d; c[i^1] += d; cap -= d; sum += d; val += d * w[i]; }
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
} A;

bool solve(cint T) {
    cin >> N;
    for(int i=1; i<=N; i++) { cin >> a[i]; }
    cin >> p >> m >> f >> n >> s;
    int ss = N*2+1;
    int tt = N*2+2;
    for(int i=1; i<=N; i++) { 
        A.add(ss, i, p, inf_ll); 
        A.add(ss, i+N, 0, a[i]);
        A.add(i, tt, 0, a[i]);
        if(i < N) { A.add(i+N, i+N+1, 0, inf_ll); }
        if(i+n <= N) { A.add(i+N, i+n, s, inf_ll); }
        if(i+m <= N) { A.add(i+N, i+m, f, inf_ll); }
    }
    auto k = A.max_flow(ss, tt);
    cout << k.second << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}