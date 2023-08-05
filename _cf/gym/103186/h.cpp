#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
ll num[100100];
struct car {
    ll p, v;
    int id;
    void init() {
        cin >> p >> v >> id;
    }
    bool operator < (const car&a) const {
        return p < a.p;
    }
} a[100100];

struct node {
    int id;
};
set<node> e;

bool operator < (const node& a, const node& b) {
    return num[a.id] > num[b.id];
}

bool check(ll x) {
    if(x <= 0) return 0;
    for(int i=1; i<=k; i++) num[i] = -inf_ll;
    e.clear();
    for(int i=1; i<=n; i++) {
        ll pre = a[i].p + a[i].v * x;
        if(!e.empty()) {
            auto r = e.begin();
            if(r->id == a[i].id) ++r;
            if(r != e.end() && num[r->id] >= pre) { return 1; }
        }
        if(e.find( {a[i].id} ) != e.end()) e.erase( {a[i].id} );
        if(num[a[i].id] < pre) num[a[i].id] = pre;
        e.insert( {a[i].id} );
    }
    return 0;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) a[i].init();
    sort(a+1, a+1+n);
    // for(int i=1; i<=n; i++)
    //     cout << a[i].p << ' ' << a[i].v << ' ' << a[i].id << endl;
    ll l = 1, r = 3e9+2, mid;
    while(l < r) {
        mid = l + (r-l) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(l-1)) --l;
    if(!check(l)) ++l;
    if(l >= 3e9+2) cout << -1 << endl;
    else cout << l-1 << endl;
    return 0;
}
/*
2 2
1 -1 1
-1 1 2
*/