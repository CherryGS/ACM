#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;

int cnt=1, root=1;
struct Node {
    int lson, rson;
    ll sum;
    int mx_laz;
    bool st;
} a[200200<<2];

void build(cint l, cint r, cint pos, cint co, int&loc) {
    if(!loc) loc = ++cnt;
    if(l==r) {
        a[loc].mx_laz = co;
        a[loc].sum = co;
        return;
    }
    int mid=(l+r)>>1;
    if(pos <= mid) build(l, mid, pos, co, a[loc].lson);
    else build(mid+1, r, pos, co, a[loc].rson);
    a[loc].sum = a[a[loc].lson].sum + a[a[loc].rson].sum;
    a[loc].mx_laz = max(a[a[loc].lson].mx_laz, a[a[loc].rson].mx_laz);
    return;
}

void push(Node&b, cint l, cint r) {
    b.st = 0;
    int mid = (l+r) >> 1;
    a[b.lson].mx_laz = b.mx_laz;
    a[b.rson].mx_laz = b.mx_laz;
    a[b.lson].sum = (mid-l+1)*b.mx_laz;
    a[b.rson].sum = (r-mid)*b.mx_laz;
    b.sum = a[b.lson].sum + a[b.rson].sum;
}

int query_mx(cint l, cint r, cint key, cint loc) {
    if(l == r) return l;
    int mid = (l+r)>>1;
    if(a[loc].st) push(a[loc], l, r);
    if(a[a[loc].rson].mx_laz <= key) return query_mx(l, mid, key, a[loc].lson);
    else return query_mx(mid+1, r, key, a[loc].rson);
}

void change(cint l, cint r, cint kl, cint kr, cint co, cint loc) {
    if(l >= kl && r <= kr) {
        a[loc].st = 1;
        a[loc].mx_laz = co;
        return;
    }
    if(a[loc].st) push(a[loc], l, r);
    int mid = (l+r) >> 1;
    if(kl <= mid) change(l, mid, kl, kr, co, a[loc].lson);
    if(kr >= mid + 1) change(mid+1, r, kl, kr, co, a[loc].rson);
    a[loc].mx_laz = max(a[a[loc].lson].mx_laz, a[a[loc].rson].mx_laz);
}

ll query_sum(cint l, cint r, cint kl, cint kr, cint loc) {
    if(l >= kl && r <= kr) {
        return a[loc].sum;
    }
    if(a[loc].st) push(a[loc], l, r);
    ll pre=0;
    int mid=(l+r)>>1;
    if(kl <= mid) pre += query_sum(l, mid, kl, kr, a[loc].lson);
    if(kr >= mid+1) pre += query_sum(mid+1, r, kl, kr, a[loc].rson);
    return pre;
}

int query_ans(cint l, cint r, ll&key, cint loc) {
    if(l == r) return l;
    int mid = (l+r)>>1;
    if(a[a[loc].rson].sum >= key) return query_ans(mid+1, r, key, a[loc].rson);
    else return query_ans(l, mid, key-a[a[loc].rson].sum, a[loc].lson);
}

int main() {
    ios::sync_with_stdio(false);
    int t, x, y;
    cin >> n >> q;
    int tmp;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        build(0, n+1, i, tmp, root);
    }
    build(0, n+1, n+1, 0, root);
    build(0, n+1, 0, inf_int, root);
    for(int i=1; i<=q; i++) {
        cin >> t >> x >> y;
        if(t==1) {
            int s = query_mx(0, n+1, y, root) + 1;
            if(s <= x) change(0, n+1, s, x, y, root);
        } else {
            int s = x;
            while(s <= n) {

            }
        }   
    }
    // for(int i=1; i<=n; i++) {
    //     cout << i << ' ' <<  query_mx(0, n+1, i, root) << endl;
    // }
    return 0;
}