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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

int n, q;
int node[200200<<2], mx[200200<<2], mn[200200<<2];
int lef[200200<<2], rit[200200<<2];
bool tr[200200<<2];

void build(cint l, cint r, cint loc) {
    if(l == r) {
        cin >> node[loc];
        tr[loc] = 1;
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
    if(tr[ls] && tr[rs] && mx[ls] <= mn[rs]) tr[loc] = 1;
}

void update(cint l, cint r, cint loc, cint ds, cint co) {
    if(l == r) {
        node[loc] = co;
        return;
    }
    int mid = (l+r) >> 1;
    if(ds <= )
    mn[loc] = min(mn[ls], mn[rs]);
    mx[loc] = max(mx[ls], mx[rs]);
    if(tr[ls] && tr[rs] && mx[ls] <= mn[rs]) tr[loc] = 1;
}

int main() {
    cin >> n >> q;
    build(1, n, 1);
    int tmp, x, y;
    for(int i=1; i<=q; i++) {
        cin >> tmp >> x >> y;
        if(tmp == 1) {
            update(1, n, 1, x, y);
        } else {

        }
    }
    return 0;
}