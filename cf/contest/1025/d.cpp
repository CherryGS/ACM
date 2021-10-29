#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mxn = 1404; // 最大点数
const int mxm = 700*700/2 + 700*2; // 最大边数
struct dinic {
    int s, t; // 源，汇
    ll w[mxm*2];
    int h[mxn], nx[mxm*2], to[mxm*2], cnt=1; // 链式前向星, cnt=1 方便找到反边
    int cur[mxn]; // 当前弧优化辅助数组
    int label[mxn]; // 分层图标号
    void clear_map() { cnt = 1; for(int i=1; i<mxn; i++) h[i] = 0; }
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
    ll dfs(cint loc, ll cap) {
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
    ll max_flow(cint s, cint t) {
        this->s = s;
        this->t = t;
        ll flow = 0;
        while(bfs()) { flow += dfs(s, inf_ll); }
        return flow;
    }

    dinic() { clear_map(); }
};

int n;
int a[1010];

int gcd(cint x, cint y) {
    return y ? gcd(y, x%y) : x;
}

dinic AC;

int main() {
    cin >> n;
    int s = 2*n+1, t = 2*n+2;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        AC.add(s, i, 2);
        AC.add(i+n, t, 1);
        for(int j=1; j<=n; j++) if(i != j){
            if(gcd(a[i], a[j]) != 1) {
                AC.add(i, j+n, 1);
            }
        }
    }
    int r = AC.max_flow(s, t);
    // cout << AC.cnt << ' ' << r << endl;
    if(r == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}