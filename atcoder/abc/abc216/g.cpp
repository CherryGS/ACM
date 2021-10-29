#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_n = 200000;
int node[mx_n<<2], lz[mx_n<<2];

void push(cint loc, cint l, cint r) {
    int mid = (l+r) >> 1;
    lz[ls] = 1;
    lz[rs] = 1;
    lz[loc] = 0;
    node[ls] = mid-l+1;
    node[rs] = r-mid;
}

int q_sum(cint l, cint r, cint loc, cint dr) {
    if(r <= dr) {
        return node[loc];
    }
    if(lz[loc]) push(loc, l, r);
    int mid = (l+r) >> 1;
    int sum = 0;
    sum += q_sum(l, mid, ls, dr);
    if(dr >= mid+1) sum += q_sum(mid+1, r, rs, dr);
    node[loc] = node[ls] + node[rs];
    return sum;
}

int query(cint l, cint r, cint loc, cint co) {
    if(l == r) {
        return l;
    }
    if(lz[loc]) push(loc, l, r);
    int mid = (l+r) >> 1;
    if(node[ls] >= co) return query(l, mid, ls, co);
    else return query(mid+1, r, rs, co-(node[ls]));
}

void update(cint l, cint r, cint ds, cint loc) {
    if(l >= dl) {
        node[loc] = r-l+1;
        lz[loc] = 1;
        return;
    }
    if(lz[loc]) push(loc, l, r);
    int mid = (l+r) >> 1;
    if(ds <= mid) update(l, mid, ds, ls);
    update(mid+1, r, ds, rs);
    node[loc] = node[ls] + node[rs];
}

struct stu { int l, r, x; bool operator < (const stu&a) const { return (r == a.r? x > a.x: r < a.r ); } } s[200200];

int n, m;

int main() {
    cin >> n >> m;
    int l, r, x;
    for(int i=1; i<=m; i++) {
        cin >> l >> r >> x;
        s[i] = {l, r, x};
    }
    sort(s+1, s+1+m);
    for(int i=1; i<=m; i++) {
        
    }
    return 0;
}