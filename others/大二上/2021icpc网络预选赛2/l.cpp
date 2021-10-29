#include <bits/stdc++.h>
using namespace std;

#define cint const int&
#define ll long long
#define ls (loc<<1)
#define rs ((loc<<1)|1)
const int mod = 998244353;
int n, m;
vector<int> q[101];
ll node[100100<<3];
bool vis[40][100100<<3];
int e[101];
int to[101];
int cnt;
ll lz[100100<<3];

void push(cint loc) {
    lz[ls] = lz[ls] * lz[loc] % mod;
    lz[rs] = lz[rs] * lz[loc] % mod;
    node[ls] = node[ls] * lz[loc] % mod;
    node[rs] = node[rs] * lz[loc] % mod;
    lz[loc] = 1;
    node[loc] = (node[ls] + node[rs]) % mod;
}

void update(cint l, cint r, cint dl, cint dr, cint loc, cint pri) {
    if(dl <= l && dr >= r && vis[pri][loc]) {
        node[loc] = (node[loc] * to[pri]) % mod;
        lz[loc] = (lz[loc] * to[pri]) % mod;
        return;
    }
    if(l == r) {
        vis[pri][loc] = 1;
        node[loc] = (node[loc] * (to[pri]-1)) % mod;
        return;
    }
    if(lz[loc] > 1) push(loc);
    int mid = (l+r) >> 1;
    if(dl <= mid) update(l, mid, dl, dr, ls, pri);
    if(dr >= mid+1) update(mid+1, r, dl, dr, rs, pri);
    node[loc] = (node[ls] + node[rs]) % mod;
    vis[pri][loc] = vis[pri][ls] & vis[pri][rs];
}

ll query(cint l, cint r, cint dl, cint dr, cint loc) {
    if(dl <= l && dr >= r) {
        return node[loc];
    }
    if(lz[loc] > 1) push(loc);
    ll ans = 0;
    int mid = (l+r) >> 1;
    if(dl <= mid) ans += query(l, mid, dl, dr, ls);
    if(dr >= mid+1) ans += query(mid+1, r, dl, dr, rs);
    return ans % mod;
}

void init() {
    for(int i=2; i<=100; i++) {
        int r = i;
        for(int j=2; j<=sqrt(i); j++) {
            while(!(r%j)) {
                q[i].push_back(j);
                r /= j;
            }
        }
        if(r > 1) q[i].push_back(r);
        if(r == i) e[r] = ++cnt, to[cnt] = r;
    }
}

void build(cint l, cint r, cint loc) {
    if(l == r) {
        node[loc] = 1;
        return;
    }
    int mid = (l+r) >> 1;
    lz[loc] = 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    node[loc] = node[ls] + node[rs];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init();
    int tmp;
    build(1, n, 1);
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        for(int v: q[tmp]) {
            update(1, n, i, i, 1, e[v]);
        }
    }
    bool st;
    int l, r, w;
    for(int i=1; i<=m; i++) {
        cin >> st >> l >> r;
        if(st == 0) {
            cin >> w;
            if(w != 1)
            for(int v: q[w]) {
                update(1, n, l, r, 1, e[v]);
            }
        }
        else {
            cout << query(1, n, l, r, 1);
            if(i != m) cout << '\n';
        }
    }
}
/*
5 2
1 1 1 1 1
0 1 5 2
1 1 5
*/