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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

struct node {
    int l, r, x;
    void init() { cin >> l >> r >> x; }
};

int n, q;
int a[500500];
ll sum[500500];
node li[500500];
priority_queue<int, vector<int>, greater<int>> que;

int lowbit(int x) { return x & -x; }

ll query(int x) {
    if(x <= 0 || x > n) { return 0; }
    ll ans = 0;
    while(x > 0) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x, int val) {
    while(x <= n) {
        sum[x] += val;
        x += lowbit(x);
    }
}

void mv(int x) {
    while(x <= n) {
        sum[x] = 0;
        x += lowbit(x);
    }
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    cin >> q;
    for(int i=1; i<=q; i++) { li[i].init(); }
    for(int i=1; i<=n+10; i++) { sum[i] = 0; }
    int id = 0, ed = 1;
    queue<int> tmp;
    for(int i=1; i<=q+1; i++) {
        auto &now = li[i];
        if(i > 1 && ((li[i].x > 0 && li[i-1].x <= 0) || (i == q+1 && li[i-1].x <= 0))) {
            while(!que.empty()) {
                auto k = que.top();
                ll val = query(k-1);
                // cout << i << ' ' << c << ' ' << j << ' ' << que[j]-1 << ' ' << val << endl;
                // for(int i=1; i<=n; i++) { cout << sum[i] << ' '; }
                // cout << endl;
                // 我
                if(val < 0) {
                    id = i-1;
                    while(!que.empty()) { que.pop(); }
                    while(!tmp.empty()) { mv(tmp.front()); tmp.pop(); }
                    break;
                }
                else if(val > 0) { break; }
                val = query(k);
                if(val < 0) {
                    id = i-1;
                    while(!que.empty()) { que.pop(); }
                    while(!tmp.empty()) { mv(tmp.front()); tmp.pop(); }
                    break;
                }
                else if(val > 0) { break; }
                que.pop();
            }
        }
        if(i == q+1) { break; }
        if(now.x == 0) { continue; }
        add(now.l, now.x); add(now.r+1, -now.x);
        // que[++c] = now.l; que[++c] = now.r+1;
        que.push(now.l); que.push(now.r+1);
        tmp.push(now.l); tmp.push(now.r+1);
    }
    while(!tmp.empty()) { mv(tmp.front()); tmp.pop(); }
    for(int i=1; i<=id; i++) {
        auto &r = li[i];
        sum[r.l] += r.x; sum[r.r+1] -= r.x;
    }
    // cout << id << endl;
    for(int i=1; i<=n; i++) { sum[i] += sum[i-1]; cout << sum[i]+a[i] << ' '; }
    cout << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
