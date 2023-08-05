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

const int L = 1;
const int R = 2e5+1000;

int n, q;

int a[200200];
int b[200200+2000];
int mx[200200<<4];
int mn[200200<<4];
int lz[200200<<4];

void push(int loc) {
    lz[ls] = lz[rs] = lz[loc];
    mx[ls] = mn[ls] = mx[rs] = mn[rs] = lz[loc] - 1;
    lz[loc] = 0;
}

void update(int l, int r, int dl, int dr, int loc, int val) {
    if(l > r) { return; }
    if(l >= dl && r <= dr) {
        mx[loc] = val;
        mn[loc] = val;
        lz[loc] = val + 1;
        return;
    }
    int mid = (l+r) >> 1;
    if(lz[loc]) { push(loc); }
    if(dl <= mid) { update(l, mid, dl, dr, ls, val); }
    if(dr >= mid + 1) { update(mid+1, r, dl, dr, rs, val); }
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
}

int query_mn(int l, int r, int dl, int dr, int loc) {
    if(l >= dl && r <= dr) {
        return mn[loc];
    }
    int mid = (l+r) >> 1;
    int ans = inf_int;
    if(lz[loc]) { push(loc); }
    if(dl <= mid) { ans = min(ans, query_mn(l, mid, dl, dr, ls)); }
    if(dr >= mid + 1) { ans = min(ans, query_mn(mid+1, r, dl, dr, rs)); }
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
    return ans;
}

int query_mx(int l, int r, int dl, int dr, int loc) {
    if(l >= dl && r <= dr) {
        return mx[loc];
    }
    int mid = (l+r) >> 1;
    int ans = -1;
    if(lz[loc]) { push(loc); }
    if(dl <= mid) { ans = max(ans, query_mx(l, mid, dl, dr, ls)); }
    if(dr >= mid + 1) { ans = max(ans, query_mx(mid+1, r, dl, dr, rs)); }
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
    return ans;
}

int find_zero(int dl, int dr) {
    // cout << dl << ' ' << dr << endl;
    // for(int i=1; i<=10; i++) { cout << query_mn(L, R, i, i, 1) << ' '; }
    // cout << endl;
    int mid;
    while(dl < dr) {
        // cout << dl << ' ' << mid << ' ' << dr << ' ' << query_mn(L, R, dl, mid, 1) << endl;
        mid = dl + (dr - dl)/2;
        if(query_mn(L, R, dl, mid, 1) == 0) { dr = mid; }
        else { dl = mid + 1; }
    }
    return dl;
}

int find_one(int dl, int dr) {
    int mid;
    while(dl < dr) {
        mid = dl + (dr - dl)/2;
        if(query_mx(L, R, dl, mid, 1) == 1) { dr = mid; }
        else { dl = mid + 1; }
    }
    return dl;
}

int query_ans() {
    int l = L, r = R, mid;
    while(l < r) {
        mid = l + (r-l+1)/2;
        if(query_mx(L, R, mid, r, 1) == 1) { l = mid; }
        else { r = mid - 1; } 
    }
    return l;
}

void add(int x) {
    int t = query_mn(L, R, x, x, 1);
    // cout << t << endl;
    if(t == 0) { update(L, R, x, x, 1, 1); }
    else {
        update(L, R, x, x, 1, 0);
        // cout << query_mn(L, R, x, x, 1) << endl;
        int nx = find_zero(x+1, R);
        // cout << nx << endl;
        update(L, R, x+1, nx-1, 1, 0);
        update(L, R, nx, nx, 1, 1);
    }
}

void del(int x) {
    int t = query_mn(L, R, x, x, 1);
    if(t == 1) { update(L, R, x, x, 1, 0); }
    else {
        update(L, R, x, x, 1, 1);
        int nx = find_one(x+1, R);
        update(L, R, x+1, nx-1, 1, 1);
        update(L, R, nx, nx, 1, 0);
    }
}

void build(int l, int r, int loc) {
    if(l == r) {
        mx[loc] = b[l];
        mn[loc] = b[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
}

void solve(cint T) {
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        ++b[a[i]];
    }
    for(int i=L; i<=R; i++) {
        b[i+1] += b[i] / 2;
        b[i] %= 2;
    }
    build(L, R, 1);
    for(int i=1; i<=q; i++) {
        int k, l;
        cin >> k >> l;
        add(l);
        del(a[k]);
        // cout << l << ' ' << a[k] << endl;
        // for(int i=1; i<=15; i++) { cout << query_mn(L, R, i, i, 1) << ' '; }
        // cout << endl;
        a[k] = l;
        cout << query_ans() << '\n';
    }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}