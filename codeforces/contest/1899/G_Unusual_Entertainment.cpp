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
#define ifor(s, e) for(int i=s;i<=e;i+=1)
#define jfor(s, e) for(int j=s;j<=e;j+=1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

namespace GT {
    char gc() {
        const int S = 1 << 16; // 2^16 = 65536
        static char buf[S], *s = buf, *t = buf;
        if (s == t) t = buf + fread(s = buf, 1, S, stdin);
        if (s == t) return EOF;
        return *s++;
    }
    int gti() {
        int a = 0, b = 1, c = gc();
        for (; !isdigit(c); c = gc()) b ^= (c == '-');
        for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
        return b ? a : -a;
    }
    int gts(char *s) {
        int len = 0, c = gc();
        for (; isspace(c); c = gc());
        for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
        s[len] = 0;
        return len;
    }
    int gtl(char *s) {
        int len = 0, c = gc();
        for (; isspace(c); c = gc());
        for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
        s[len] = 0;
        return len;
    }
}

using GT::gti; // long long
using GT::gts; // char*
using GT::gtl; // line

int n, q;
vector<int> to[100100];
int p[100100];
int dfn[100100], lst[100100], cnt;
int loc[100100];

struct nod {
    int l, r, x, id;
    bool ans;
    void init(int i) { l = gti(); r = gti(); x = gti(); id = i; ans = 0; }
} s[100100];

void dfs(int u, int f) {
    dfn[u] = ++cnt;
    for(auto &v: to[u]) {
        if(v != f) {
            dfs(v, u);
        }
    }
    lst[u] = cnt;
}

int seg[100100<<2];

void update(int nl, int nr, int des, int loc, int val) {
    if(nl == nr) {
        seg[loc] = val;
        return;
    }
    int mid = (nl+nr) / 2;
    if(des <= mid) { update(nl, mid, des, ls, val); }
    else { update(mid+1, nr, des, rs, val); }
    seg[loc] = max(seg[ls], seg[rs]);
}

int query(int nl, int nr, int l, int r, int loc) {
    if(nl >= l && nr <= r) {
        return seg[loc];
    }
    int mid = (nl+nr) / 2;
    int ans = 0;
    if(l <= mid) { ans = max(ans, query(nl, mid, l, r, ls)); }
    if(r >= mid+1) { ans = max(ans, query(mid+1, nr, l, r, rs)); }
    return ans;
}

void build(int nl, int nr, int loc) {
    seg[loc] = 0;
    if(nl == nr) { return; }
    int mid = (nl+nr) / 2;
    build(nl, mid, ls);
    build(mid+1, nr, rs);
}

void solve(cint T) {
    cnt = 0;
    n = gti(); q = gti();
    build(1, n, 1);
    int u, v;
    ifor(1, n) { to[i].clear(); }
    ifor(1, n-1) { u = gti(); v = gti(); to[u].push_back(v); to[v].push_back(u); }
    ifor(1, n) { p[i] = gti(); }
    ifor(1, q) { s[i].init(i); }
    dfs(1, 1);
    ifor(1, n) { p[i] = dfn[p[i]]; loc[p[i]] = i; }
    sort(s+1, s+1+q, [](const nod&a, const nod&b) {
        return lst[a.x] < lst[b.x];
    });
    int r = 1;
    ifor(1, q) {
        while(r <= lst[s[i].x]) {
            update(1, n, loc[r], 1, r);
            ++r;
        }
        s[i].ans = (query(1, n, s[i].l, s[i].r, 1) >= dfn[s[i].x]);
    }
    sort(s+1, s+1+q, [](const nod&a, const nod&b) {
        return a.id < b.id;
    });
    ifor(1, q) {
        if(s[i].ans) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
