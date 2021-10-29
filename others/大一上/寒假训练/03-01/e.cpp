#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int bcj[200200];
map<int, int> e;
ll ans = 0;

struct edge {
    int u, v;
    int le;
    bool operator < (const edge&a) const {
        return le < a.le;
    }
    void init() {
        cin >> u >> v >> le;
    }
} a[200200];

struct query {
    ll val, id, an;
    bool operator < (const query&a) const {
        return val < a.val;
    }
    void init(cint x) {
        id = x;
        cin >> val;
    }
} b[200200];

bool cmp (const query&a, const query&b) {
    return a.id < b.id;
}

int fd(cint x) {
    return bcj[x] == x? x : fd(bcj[x]);
}

ll C(ll x) {
    return x*(x-1)/2;
}

void merge(cint x) {
    int u = a[x].u, v = a[x].v, le = a[x].le;
    if(fd(u) > fd(v)) swap(u, v);
    ans -= C(e[fd(u)]) + C(e[fd(v)]);
    e[fd(u)] = e[fd(u)]+e[fd(v)];
    ans += C(e[fd(u)]);
    e.erase(e.find(fd(v)));
    bcj[fd(v)] = fd(u);
    // cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int u, v, l;
    for(int i=1; i<n; i++) a[i].init();
    for(int i=1; i<=m; i++) b[i].init(i);
    for(int i=1; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=n; i++) e.insert(make_pair(i, 1));
    sort(a+1, a+n);
    sort(b+1, b+1+m);
    int nn = 1;
    for(int i=1; i<=m; i++) {
        int t = b[i].val;
        while(a[nn].le <= t && nn <= n) {
            // cout << a[nn].le << ' ' << nn << endl;
            merge(nn);
            ++nn;
        }
        b[i].an = ans;
    }
    sort(b+1, b+1+m, cmp);
    for(int i=1; i<=m; i++)
        cout << b[i].an << ' ';
    cout << endl;
    return 0;
}