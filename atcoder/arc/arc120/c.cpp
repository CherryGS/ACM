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

ll n;
struct stu {
    ll id;
    ll val;
    void init(ll x) {
        id = x;
        cin >> val;
        val += x;
    }
} a[200200], b[200200];
ll to[200200];
ll node[200200];

int lowbit(cint x) {
    return x&-x;
}

void add(int l, int r) {
    ++r;
    while(l <= n) {
        node[l] += 1;
        l += lowbit(l);
    }
    while(r <= n) {
        node[r] -= 1;
        r += lowbit(r);
    }
}

ll query(int x) {
    ll ans = 0;
    while(x) {
        ans += node[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp(const stu&a, const stu&b) {
    return a.val == b.val ? a.id < b.id : a.val < b.val;
}

bool check() {
    for(int i=1; i<=n; i++) {
        if(a[i].val != b[i].val) return 0;
        else to[b[i].id] = a[i].id;
    }
    return 1;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) a[i].init(i);
    for(int i=1; i<=n; i++) b[i].init(i);
    sort(a+1, a+1+n, cmp);
    sort(b+1, b+1+n, cmp);
    if(!check()) {
        cout << -1 << endl;
    } else {
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ll r = to[i] + query(to[i]);
            ans += r-i;
            add(1, to[i]-1);
        }
        cout << ans << endl;
    }
    return 0;
}