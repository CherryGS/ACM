#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

#define ls lson[loc]
#define rs rson[loc]

typedef pair<int, int> pii;
struct node1 { int id, l, r; bool operator < (const node1&a) const { return id < a.id; } } e[300300];
int n, m;
set<int> q;
map<int, int> to;
int d[300300];
bool vis[300300];

int root;
const int mx_n = 300100;
int node[mx_n*20], lson[mx_n*20], rson[mx_n*20], cnt;
int lz[mx_n*20], tag[mx_n*20];

void push(cint loc) {
    if(!ls) ls = ++cnt;
    if(!rs) rs = ++cnt;
    lz[ls] = max(lz[ls], lz[loc]);
    lz[rs] = max(lz[rs], lz[loc]);
    node[ls] = max(node[ls], lz[loc]);
    node[rs] = max(node[rs], lz[loc]);
    lz[loc] = 0;
}

void update(cint l, cint r, cint dl, cint dr, int&loc, cint co) {
    if(!loc) loc = ++cnt;
    if(l >= dl && r <= dr) {
        node[loc] = max(node[loc], co);
        lz[loc] = max(lz[loc], co);
        return ;
    }
    if(lz[loc]) push(loc);
    int mid = (l+r) >> 1;
    if(dl <= mid) update(l, mid, dl, dr, ls, co);
    if(dr >= mid+1) update(mid+1, r, dl, dr, rs, co);
    node[loc] = max(node[ls], node[rs]);
}

int query(cint l, cint r, cint dl, cint dr, int&loc) {
    if(!loc) loc = ++cnt;
    if(l >= dl && r <= dr) {
        return node[loc];
    }
    if(lz[loc]) push(loc);
    int mid = (l+r) >> 1;
    int mx = 0;
    if(dl <= mid) mx = max(mx, query(l, mid, dl, dr, ls));
    if(dr >= mid+1) mx = max(mx, query(mid+1, r, dl, dr, rs));
    return mx;
}

void debug(cint ct) {
    for(int i=1; i<=ct; i++)
        cout << query(1, ct, i, i, root) << ' ';
    cout << endl;
}

int main() {
    cin >> n >> m;
    int l, r, x;
    for(int i=1; i<=m; i++) {
        cin >> x >> l >> r;
        e[i] = {x, l, r};
        q.insert(l);
        q.insert(r);
    }
    sort(e+1, e+1+m);
    int ct = 0;

    for(auto k: q) to[k] = ++ct;
    for(int i=1; i<=m; i++) {
        e[i].l = to[e[i].l];
        e[i].r = to[e[i].r];
    }
    queue<pii> s;
    int mx_l = 0;
    int ans = 0, pre, last = 0, ans_tag;
    for(int i=1; i<=m; i++) {
        if(i > 1 && e[i].id != e[i-1].id) {
            while(!s.empty()) {
                // cout << s.front().first << ' ' << s.front().second << endl;
                update(1, ct, s.front().first, s.front().second, root, mx_l+1);
                s.pop();
            }
            // debug(ct);
            mx_l = 0;
        }
        pre = query(1, ct, e[i].l, e[i].r, root);
        // cout << i << ' ' << pre << ' ' << e[i].l << ' ' << e[i].r << endl;
        if(mx_l <= pre) {
            d[e[i].id] = last;
            last = e[i].id;
            mx_l = max(mx_l, pre);
        }
        if(ans < mx_l+1) {
            ans = mx_l+1;
            ans_tag = e[i].id;
        }
        s.emplace( e[i].l, e[i].r );
    }
    while(ans_tag) {
        vis[ans_tag] = 1;
        ans_tag = d[ans_tag];
    }
    cout << n-ans << endl;
    for(int i=1; i<=n; i++)
        if(!vis[i]) cout << i << ' ';
    cout << endl;
    
    return 0;
}