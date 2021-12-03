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

#define ls lson[loc]
#define rs rson[loc]

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
int a[200200];
ll node[200200<<6];
ll lz[200200<<6];
int lson[200200<<6], rson[200200<<6], root[2] = {1, 2} , cnt = 2;
int lst;
int l, r;

void build0(cint l, cint r, int& loc) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        node[loc] += node[lst] + a[l];
        lst = loc;
        return;
    }
    int mid = (l+r)/2;
    build0(l, mid, ls);
    build0(mid+1, r, rs);
    node[loc] = min(node[ls], node[rs]);
}
void build1(cint l, cint r, int& loc) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        node[loc] += node[lst] + a[l];
        lst = loc;
        return;
    }
    int mid = (l+r)/2;
    build1(mid+1, r, rs);
    build1(l, mid, ls);
    node[loc] = min(node[ls], node[rs]);
}

void push(cint loc) {
    lz[ls] += lz[loc];
    lz[rs] += lz[loc];
    node[ls] += lz[loc];
    node[rs] += lz[loc];
    lz[loc] = 0;
}

void update(cint l, cint r, cint dl, cint dr, cint loc, cint co) {
    if(dl <= l && dr >= r) {
        node[loc] += co;
        lz[loc] += co;
        return;
    }
    int mid = (l+r) >> 1;
    if(lz[loc] != 0) push(loc);
    if(dl <= mid) update(l, mid, dl, dr, ls, co);
    if(mid+1 <= dr) update(mid+1, r, dl, dr, rs, co);
    node[loc] = min(node[ls], node[rs]);
}

int query(cint l, cint r, cint dl, cint dr, cint loc) {
    if(l == r) return l;
    int mid = (l+r)/2;
    if(lz[loc]) push(loc);
    node[loc] = min(node[ls], node[rs]);
}

void sol(cint x, cint co) {
    update(1, n, x, n, root[0], co);
    update(1, n, 1, x, root[1], co);
    if(co > a[x]) {
        if(x < l) {
            // l = query(1, l, root[0]);
        }
        else if(x > r) {
            // r = query()
        }
    }
    a[x] = co;
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) a[i] -= 1;
    build0(1, n, root[0]);
    lst = 0;
    build1(1, n, root[1]);
    cin >> q;
    int op, s, b;
    for(int i=1; i<=q; i++) {
        cin >> op >> s >> b;
        if(op == 1) {
            sol(s, b-1);
        } else {

        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}