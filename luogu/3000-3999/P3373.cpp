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
#define lson (ls[loc])
#define rson (rs[loc])

const int mod = 571373;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll sum[400200], laz1[400200], laz2[400200];
int ls[400200], rs[400200];
int root=1, cnt=1;

int n, m, p;
ll arr[100100];

void build(cint l, cint r, int&loc) {
    if(!loc) loc = ++cnt;
    laz1[loc] = 1;
    if(l==r) {
        sum[loc] = arr[l]%p;
        return;
    }
    int mid=(l+r)>>1;
    build(l, mid, lson);
    build(mid+1, r, rson);
    sum[loc] = (sum[lson] + sum[rson]) % p;
}

void push_m(cint l, cint r, cint loc) {
    laz1[lson] = (laz1[loc]*laz1[lson]) % p;
    laz1[rson] = (laz1[loc]*laz1[rson]) % p;
    sum[lson] = (laz1[loc]*sum[lson]) % p;
    sum[rson] = (laz1[loc]*sum[rson]) % p;
    laz2[lson] = (laz1[loc]*laz2[lson]) % p;
    laz2[rson] = (laz1[loc]*laz2[rson]) % p;
    laz1[loc]=1;
}

void push_p(cint l, cint r, cint loc) {
    int mid=(l+r) >> 1;
    laz2[lson] = (laz2[lson] +laz2[loc]) % p;
    laz2[rson] = (laz2[rson] +laz2[loc]) % p;
    sum[lson] = (sum[lson]+laz2[loc] * ((mid+1-l)%p)) % p;
    sum[rson] = (sum[rson]+laz2[loc] * ((r-mid)%p)) % p;
    laz2[loc] = 0;
}

void plus1(cint l, cint r, cint kl, cint kr, cint co, int&loc) {
    if(l >= kl && r <= kr) {
        laz2[loc] = (co+laz2[loc]) % p;
        sum[loc] = (sum[loc] + (r-l+1)*co) % p;
        return;
    }
    if(laz1[loc]!=1) push_m(l, r, loc);
    if(laz2[loc]) push_p(l, r, loc);
    int mid=(l+r)>>1;
    if(kl <= mid) plus1(l, mid, kl, kr, co, lson);
    if(kr >= mid+1) plus1(mid+1, r, kl, kr, co, rson);
    sum[loc] = (sum[lson] + sum[rson]) % p;
}

void muti(cint l, cint r, cint kl, cint kr, cint co, int&loc) {
    if(l >= kl && r <= kr) {
        laz1[loc] = (co*laz1[loc]) % p;
        laz2[loc] = (co*laz2[loc]) % p;
        sum[loc] = (co*sum[loc]) % p;
        return;
    }
    if(laz1[loc]!=1) push_m(l, r, loc);
    if(laz2[loc]) push_p(l, r, loc);
    int mid=(l+r)>>1;
    if(kl <= mid) muti(l, mid, kl, kr, co, lson);
    if(kr >= mid+1) muti(mid+1, r, kl, kr, co, rson);
    sum[loc] = (sum[lson] + sum[rson]) % p;
}

ll query(cint l, cint r, cint kl, cint kr, int&loc) {
    if(l >= kl && r <= kr) {
        return sum[loc];
    }
    if(laz1[loc]!=1) push_m(l, r, loc);
    if(laz2[loc]) push_p(l, r, loc);
    int mid=(l+r)>>1;
    ll tmp=0;
    if(kl <= mid) tmp += query(l, mid, kl, kr, lson);
    if(kr >= mid+1) tmp += query(mid+1, r, kl, kr, rson);
    sum[loc] = (sum[lson] + sum[rson]) % p;
    return tmp % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p;
    int a;
    for(int i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    build(1, n, root);
    int s, x, y, k;
    for(int i=1; i<=m; i++) {
        cin >> s >> x >> y;
        if(s==1) {
            cin >> k;
            muti(1, n, x, y, k%p, root);
        } else if (s==2) {
            cin >> k;
            plus1(1, n, x, y, k%p, root);
        } else {
            cout << query(1, n, x, y, root)%p << endl;
        }
    }

    return 0;
}