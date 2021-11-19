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
const int inf_int = 0x7ffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
int a[300300];
map<int, int> e;
int cnt;
int lst[300300];
int lst1[300300];
int nb[2][300300];

int node[2][300300<<2];

void build(cint l, cint r, cint loc) {
    if(l == r) {
        node[0][loc] = nb[0][l];
        node[1][loc] = nb[1][l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    node[0][loc] = max(node[0][ls], node[0][rs]);
    node[1][loc] = min(node[1][ls], node[1][rs]);
}

void del(cint l, cint r, cint loc, cint des) {
    if(l == r) {
        node[0][loc] = 0;
        node[1][loc] = inf_int;
        return;
    }
    int mid = (l+r) >> 1;
    if(mid >= des) del(l, mid, ls, des);
    else del(mid+1, r, rs, des);
    node[0][loc] = max(node[0][ls], node[0][rs]);
    node[1][loc] = min(node[1][ls], node[1][rs]);
}

void update(cint l, cint r, cint loc, cint des, bool st, cint co) {
    if(l == r) {
        node[st][loc] = co;
        return;
    }
    int mid = (l+r) >> 1;
    if(des <= mid) update(l, mid, ls, des, st, co);
    else update(mid+1, r, rs, des, st, co);
    if(st == 0) node[0][loc] = max(node[0][ls], node[0][rs]);
    else node[1][loc] = min(node[1][ls], node[1][rs]);
}

void sol(cint x) {
    int l = nb[0][x], r = nb[1][x];
    nb[0][x] = 0, nb[1][x] = inf_int;
    // cout << x << ' ' << l << ' ' << r << " ---- " << endl;
    if(l != 0) nb[1][l] = r;
    if(r != n+1) nb[0][r] = l;
    del(1, n, 1, x);
    if(l != 0) update(1, n, 1, l, 1, r);
    if(r != n+1) update(1, n, 1, r, 0, l);
}

int query(cint l, cint r, cint dl, cint dr, cint loc, bool st) {
    // if(st == 1) cout << l << ' ' << r << ' ' << dl << ' ' << dr << ' ' << pre << endl;
    if(dl <= l && dr >= r) {
        // if(st == 1 && node[st][loc] == 0) 
        //     cout << l << " --- " << r << endl;
        return node[st][loc];
    }
    int mid = (l+r) >> 1;
    int pre = (st == 0 ? 0 : inf_int);
    if(dl <= mid) {
        if(st == 0) pre = max(pre, query(l, mid, dl, dr, ls, st));
        else pre = min(pre, query(l, mid, dl, dr, ls, st));
    }
    if(dr >= mid+1) {
        if(st == 0) pre = max(pre, query(mid+1, r, dl, dr, rs, st));
        else pre = min(pre, query(mid+1, r, dl, dr, rs, st));
    }
    return pre;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> q;
        nb[0][1] = n+1;
        nb[1][n+1] = n+1;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            if(e.find(a[i]) == e.end()) e[a[i]] = ++cnt;
            a[i] = e[a[i]];
        }
        for(int i=1; i<=n; i++) {
            nb[0][i] = lst[a[i]];
            lst[a[i]] = i;
        }
        for(int i=1; i<=n; i++) lst1[i] = n+1;
        for(int i=n; i>=1; i--) {
            nb[1][i] = lst1[a[i]];
            lst1[a[i]] = i;
        }
        build(1, n, 1);
        int s, x, l, r;
        // for(int i=1; i<=n; i++)cout << a[i] << ' ';
        // cout << endl;
        for(int i=1; i<=q; i++) {
            // cout << " --------------------- " << endl;
            // for(int i=1; i<=n; i++) cout << nb[1][i] << ' ';
            // cout << endl;
            // for(int i=1; i<=n; i++) {
            //     cout << query(1, n, i, i, 1, 0) << " ----- " << query(1, n, i, i, 1, 1) << endl;
            // }
            // cout << query(1, n, 1, 2, 1, 1) << endl;
            cin >> s;
            if(s == 1) { 
                cin >> x;
                sol(x);
            } else {
                cin >> l >> r;
                int a = query(1, n, l, r, 1, 0);
                int b = query(1, n, l, r, 1, 1);
                // cout << a << " --- --- " << b << endl;
                if(a < l && b > r) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }
    return 0;
}