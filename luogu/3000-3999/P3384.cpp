#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

#define ls lson[loc]
#define rs rson[loc]

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, root, p;
int h[100100], nx[200200], to[200200], cnt;
ll val[100100];
int top[100100], fa[100100];
int dep[100100], sons[100100], hson[100100];
int dfn[100100], inv_dfn[100100], dfn_num;
int end_son[100100];

inline int read() {
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void add_edge(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void dfs_1(cint loc, cint faa) {
    fa[loc] = faa;
    dep[loc] = dep[faa] + 1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != faa) {
            ++sons[loc];
            dfs_1(to[i], loc);
            if(sons[to[i]] > sons[hson[loc]])
                hson[loc] = to[i];
        }
}

void dfs_2(cint loc, cint faa) {
    dfn[loc] = ++dfn_num;
    inv_dfn[dfn_num] = loc;
    if(hson[loc]) {
        top[hson[loc]] = top[loc];
        dfs_2(hson[loc], loc);
    }
    for(int i=h[loc]; i; i=nx[i]) 
        if(to[i] != faa && to[i] != hson[loc]) {
            top[to[i]] = to[i];
            dfs_2(to[i], loc);
        }
    end_son[loc] = dfn_num;
}

const int mx_node = 100000;
int lson[mx_node<<5], rson[mx_node<<5], cnt_tree;
ll sum[mx_node<<5], lazy[mx_node<<5];
int rt;

void build(cint l, cint r, int&loc) {
    if(!loc) loc = ++cnt_tree;
    if(l == r) {
        sum[loc] = val[inv_dfn[l]] % p;
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    sum[loc] = (sum[ls] + sum[rs]) % p;
}

void push(cint loc, cint l, cint r) {
    int mid = (l+r) >> 1;
    (lazy[ls] += lazy[loc]) %= p;
    (lazy[rs] += lazy[loc]) %= p;
    (sum[ls] += (mid-l+1)*lazy[loc]) %= p;
    (sum[rs] += (r-mid)*lazy[loc]) %= p;
    lazy[loc] = 0;
}

void add(cint l, cint r, cint dl, cint dr, cint co, cint loc) {
    if(l >= dl && r <= dr) {
        sum[loc] += (r-l+1)*co;
        lazy[loc] += co;
        sum[loc] %= p;
        lazy[loc] %= p;
        return;
    }
    int mid = (l+r) >> 1;
    if(lazy[loc]) push(loc, l, r);
    if(dl <= mid) add(l, mid, dl, dr, co, ls);
    if(dr >= mid+1) add(mid+1, r, dl, dr, co, rs);
    sum[loc] = (sum[ls] + sum[rs]) % p;
}

ll query(cint l, cint r, cint dl, cint dr, cint loc) {
    if(l >= dl && r <= dr) return sum[loc];
    if(lazy[loc]) push(loc, l, r);
    int mid = (l+r) >> 1;
    ll tmp = 0;
    if(dl <= mid) tmp += query(l, mid, dl, dr, ls);
    if(dr >= mid+1) tmp += query(mid+1, r, dl, dr, rs);
    return tmp % p;
}

void oper_1(int x, int y, cint co) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        add(1, n, dfn[top[x]], dfn[x], co, rt);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    add(1, n, dfn[x], dfn[y], co, rt);
}

void oper_2(int x, int y) {
    ll ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, n, dfn[top[x]], dfn[x], rt);
        ans %= p;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ans += query(1, n, dfn[x], dfn[y], rt);
    ans %= p;
    printf("%lld\n", ans);
}

void oper_3(cint x, cint z) {
    add(1, n, dfn[x], end_son[x], z, rt);
}

void oper_4(cint x) {
    ll ans = 0;
    ans = query(1, n, dfn[x], end_son[x], rt);
    printf("%lld\n", ans);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &root, &p);
    for(int i=1; i<=n; i++) scanf("%d", &val[i]);
    int x, y;
    for(int i=1; i<n; i++) {
        scanf("%d%d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    top[root] = root;
    dfs_1(root, root);
    dfs_2(root, root);
    build(1, n, rt);

    int sw, z;
    for(int i=1; i<=m; i++) {
        scanf("%d", &sw);
        if(sw == 1) {
            scanf("%d%d%d", &x, &y, &z);
            oper_1(x, y, z%p);
        } else if(sw == 2) {
            scanf("%d%d", &x, &y);
            oper_2(x, y);
        } else if(sw == 3) {
            scanf("%d%d", &x, &z);
            oper_3(x, z%p);
        } else {
            scanf("%d", &x);
            oper_4(x);
        }
    }

    return 0;
}