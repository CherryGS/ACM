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

int n, k;
int a[100100];

struct node {
    int x, c, v;
    bool operator < (const node&a) const {
        return x == a.x ? (v == a.v ? c < a.c : v < a.v) : x < a.x;
    }
    void p() {
        cout << x << ' ' << c << ' ' << v << endl;
    }
};

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    if(a[n] <= k) { cout << 0 << '\n'; return; }
    int cnt = n*1000, ans = inf_int, mn = a[1];
    priority_queue<node, vector<node>> q;
    for(int i=1; i<=n; i++) {
        int t = min(k, a[i]/mn);
        q.push({a[i]/t, t, a[i]}); 
    }
    while(cnt) {
        auto u = q.top();
        q.pop();
        ans = min(ans, u.x - mn);
        if(u.c == k) { break; }
        if(ans == 0) { break; }
        int t = min(k, u.c+1);
        // int t = min(k, (u.v-1) / (u.x-1) + 1);
        int r = u.v / t;
        mn = min(mn, r);
        q.push({r, t, u.v});
        --cnt;
    }
    cout << ans << '\n';
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