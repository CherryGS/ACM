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

const int mxn = 202; // 最大点数
const int mxm = 5005; // 最大边数
struct dinic {
    int s, t; // 源，汇
    ll w[mxm*2];
    int h[mxn], nx[mxm*2], to[mxm*2], cnt=1; // 链式前向星, cnt=1 方便找到反边
    int cur[mxn]; // 当前弧优化辅助数组
    int label[mxn]; // 分层图标号
    void clear_map() { cnt = 1; for(int i=1; i<=mxn; i++) h[i] = 0; }
    void add(int f, int t, int co) {
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
    ll dfs(int loc, ll cap) {
        if(loc == t) return cap;
        ll sum = 0;
        for(int i=cur[loc]; i; i=nx[i]) {
            cur[loc] = i;
            if(label[to[i]] == label[loc] + 1) {
                ll d = dfs(to[i], min(cap, w[i]));
                if(d) { w[i] -= d; w[i^1] += d; cap -= d; sum += d; }
                if(!cap) break;
            }
        }
        return sum;
    }
    ll max_flow(int s, int t) {
        this->s = s;
        this->t = t;
        ll flow = 0;
        while(bfs()) { flow += dfs(s, inf_ll); }
        return flow;
    }
} A;

bool solve(cint T) {
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}