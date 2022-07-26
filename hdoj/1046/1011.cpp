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

int n, qq;
int mx[2][100100];

struct node {
    int x, y, w;
    void init() {
        int t1, t2;
        cin >> t1 >> t2 >> w;
        x = t1 + t2;
        y = t1 - t2;
    }
} a[100100];


struct query {
    int x, y, id;
    int ans;
    void init(int r) {
        int t1, t2;
        cin >> t1 >> t2;
        x = t1 + t2;
        y = t1 - t2;
        id = r;
        ans = 0;
    }
    bool operator < (const query&a) const {
        return id < a.id;
    }
} q[100100];

bool cmp1(const query&a, const query&b) {
    return a.x < b.x;
}

bool cmp2(const query&a, const query&b) {
    return a.y < b.y;
}

bool cmp3(const node&a, const node&b) {
    return a.x < b.x;
}

bool cmp4(const node&a, const node&b) {
    return a.y < b.y;
}

int cacu(int query, int node, bool st) {
    if(st == 0)
    return min(abs(q[query].x-a[node].x), a[node].w);
    return min(abs(q[query].y-a[node].y), a[node].w);
}

void solve(cint T) {
    cin >> n >> qq;
    for(int i=1; i<=n; i++) { a[i].init(); }
    for(int i=1; i<=qq; i++) { q[i].init(i); }
    sort(a+1, a+1+n, cmp3);
    for(int i=1; i<=n+1; i++) { mx[0][i] = mx[1][i] = 0;}
    for(int i=1; i<=n; i++) { mx[0][i] = max(mx[0][i-1], a[i].w); }
    for(int i=n; i>=1; i--) { mx[1][i] = max(mx[1][i+1], a[i].w); }
    sort(q+1, q+1+qq, cmp1);
    int r = 1;
    // for(int i=1; i<=n; i++) { cout << a[i].w << ' '; }
    // cout << endl;
    for(int i=1; i<=qq; i++) {
        while(r <= n && a[r].x - q[i].x <= mx[1][r]) { ++r; }
        if(r <= n) { q[i].ans = max(q[i].ans, mx[1][r]); }
        if(r > 1) { q[i].ans = max(q[i].ans, cacu(i, r-1, 0)); }
    }
    r = n;
    for(int i=qq; i>=1; i--) {
        while(r >= 1 && q[i].x - a[r].x <= mx[0][r]) { --r; }
        // cout << i << ' ' << r << ' ' << cacu(i, r, 0) << ' ' << q[i].id << endl;
        if(r >= 1) { q[i].ans = max(q[i].ans, mx[0][r]); }
        if(r < n) { q[i].ans = max(q[i].ans, cacu(i, r+1, 0)); }
    }

    sort(a+1, a+1+n, cmp4);
    for(int i=1; i<=n+1; i++) { mx[0][i] = mx[1][i] = 0;}
    for(int i=1; i<=n; i++) { mx[0][i] = max(mx[0][i-1], a[i].w); }
    for(int i=n; i>=1; i--) { mx[1][i] = max(mx[1][i+1], a[i].w); }
    sort(q+1, q+1+qq, cmp2);
    r = 1;
    for(int i=1; i<=qq; i++) {
        while(r <= n && a[r].y - q[i].y <= mx[1][r]) { ++r; }
        if(r <= n) { q[i].ans = max(q[i].ans, mx[1][r]); }
        if(r > 1) { q[i].ans = max(q[i].ans, cacu(i, r-1, 1)); }
    }
    r = n;
    for(int i=qq; i>=1; i--) {
        while(r >= 1 && q[i].y - a[r].y <= mx[0][r]) { --r; }
        if(r >= 1) { q[i].ans = max(q[i].ans, mx[0][r]); }
        if(r < n) { q[i].ans = max(q[i].ans, cacu(i, r+1, 1)); }
    }
    sort(q+1, q+1+qq);
    for(int i=1; i<=qq; i++) { cout << q[i].ans << '\n'; }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}