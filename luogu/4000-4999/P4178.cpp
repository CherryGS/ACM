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

int n;
int h[40010], nx[80020], to[80020], w[80020], cnt; // 链式前向星数组
int son[40010]; // 经过处理后的每个点的儿子个数
bool vis[40010]; // 该点是否在分治时作为子树的根
int id; // 当前所处理的树的重心
int snode; // 当前所处理树的节点数量

int mx;
int sr[20020];
int zr;
int ans;

int lowbit(cint x) { return x&-x; }

void add(int x) {
    while(x <= mx) {
        ++sr[x];
        x += lowbit(x);
    }
}

int query(int x) {
    int ans = 0;
    while(x) {
        ans += sr[x];
        x -= lowbit(x);
    }
    return ans;
}

int gsiz(cint loc, cint fa) {
    int sum = 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            sum += gsiz(to[i], loc);
        }
    return sum;
}

void gp(cint loc, cint fa) {
    int pre = 0;
    son[loc] = 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            gp(to[i], loc);
            pre = max(pre, son[to[i]]);
            son[loc] += son[to[i]];
            if(id) return;
        }
    pre = max(pre, snode - son[loc]);
    // 树的重心可能有两个，此处任取了一个
    if(pre <= snode/2) {
        id = loc;
        return;
    }
}

void check(cint loc, cint fa, cint co) {
    if(co > mx) return;
    ans += query(mx-co) + zr;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && !vis[to[i]]) {
            check(to[i], loc, co + w[i]);
        }
}

void update(cint loc, cint fa, cint co) {
    if(co > mx) return;
    if(co) add(co);
    else ++ zr;
    for(int i=h[loc]; i; i=nx[i]) {
        if(to[i] != fa && !vis[to[i]]) {
            update(to[i], loc, co + w[i]);
        }
    }
}

void sol(cint loc) {
    vis[loc] = 1;
    for(int i=1; i<=mx; i++) sr[i] = 0;
    zr = 1;
    for(int i=h[loc]; i; i=nx[i]) {
        if(!vis[to[i]]) {
            check(to[i], loc, w[i]);
            update(to[i], loc, w[i]);
        }
    }
    for(int i=h[loc]; i; i=nx[i]) {
        if(!vis[to[i]]) {
            snode = gsiz(to[i], loc);
            id = 0;
            gp(to[i], loc);
            sol(id);
        }
    }
}

void add(cint f, cint t, cint co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

int main() {
    cin >> n;
    int u, v, co;
    for(int i=1; i<n; i++) {
        cin >> u >> v >> co;
        add(u, v, co);
        add(v, u, co);
    }
    cin >> mx;
    snode = n;
    gp(1, 1);
    sol(id);
    cout << ans << endl;
    return 0;
}