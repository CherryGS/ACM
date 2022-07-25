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

struct node {
    int x, p, id;
    void init(int r) {
        id = r;
        cin >> x >> p;
    }
    bool operator < (const node&a) const {
        return x < a.x;
    }
};

int n, m;
ll sum[200200], mx[200200];
node a[200200];
bool ans[200200];

bool cmp(cint x, cint y) {
    return a[x].id < a[y].id;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { a[i].init(i); }
    for(int i=1; i<=n; i++) { mx[i] = ans[i] = sum[i] = 0; }
    sort(a+1, a+1+n);
    multiset<ll> q;
    q.insert(a[1].x + a[1].p);
    ll s = *q.begin();
    for(int i=2; i<=n; i++) {
        // cout << s << endl;
        // for(auto k: q) { cout << k << ' '; }
        // cout << endl;
        while(!q.empty()) {
            int k = *q.begin();
            if(k - a[i].x > 0) { break; }
            s -= *q.begin();
            q.erase(q.begin());
        }
        // cout << i << ' ' << s << ' ' << q.size() << ' ' << sum[i] << ' ' << s - 1ll * q.size() * a[i].x << endl;
        sum[i] += s - 1ll * q.size() * a[i].x;
        s += a[i].x + a[i].p;
        q.insert(a[i].x + a[i].p);
    }
    // for(int i=1; i<=n; i++) { cout << sum[i] << ' '; }
    // cout << endl;
    q.clear();
    q.insert(-a[n].x + a[n].p);
    s = *q.begin();
    for(int i=n-1; i>=1; i--) {
        while(!q.empty()) {
            int k = *q.begin();
            if(k + a[i].x > 0) { break; }
            s -= *q.begin();
            q.erase(q.begin());
        }
        sum[i] += s + 1ll * q.size() * a[i].x;
        s += - a[i].x + a[i].p;
        q.insert(-a[i].x+a[i].p);
    }
    q.clear();
    if(sum[1]+a[1].p-m > 0)
    q.insert(sum[1]+a[1].p-m-a[1].x);
    for(int i=2; i<=n; i++) {
        // if(*q.rbegin() > 0)
        if(q.size())
        mx[i] = max(mx[i], *q.rbegin()+a[i].x);
        if(sum[i]+a[i].p-m > 0)
        q.insert(sum[i]+a[i].p-m-a[i].x);
    }
    q.clear();
    if(sum[n]+a[n].p-m > 0)
    q.insert(sum[n]+a[n].p-m+a[n].x);
    for(int i=n-1; i>=1; i--) {
        if(q.size())
        mx[i] = max(mx[i], *q.rbegin()-a[i].x);
        if(sum[i]+a[i].p-m > 0)
        q.insert(sum[i]+a[i].p-m+a[i].x);
    }
    // for(int i=1; i<=n; i++) { cout << mx[i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n; i++) { cout << sum[i] + a[i].p - m << ' '; }
    // cout << endl;
    for(int i=1; i<=n; i++) { ans[a[i].id] = (sum[i] <= m && mx[i] <= a[i].p); }
    for(int i=1; i<=n; i++) { cout << ans[i]; }
    cout << '\n';
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