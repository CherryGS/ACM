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

int n, m;
int node[200200<<4];
ll sum[200200];

void update(int l, int r, int loc, int d, int val) {
    if(l == r) {
        node[loc] += val;
        return;
    }
    int mid = (l+r) >> 1;
    if(d <= mid) { update(l, mid, ls, d, val); }
    else { update(mid+1, r, rs, d, val); }
    node[loc] = min(node[ls], node[rs]);
}

int query(int l, int r, int loc) {
    if(l == r) { return l; }
    int mid = (l+r) >> 1;
    if(node[ls] <= node[rs]) { return query(l, mid, ls); }
    else { return query(mid+1, r, rs); }
}

void solve(cint T) {
    cin >> n >> m;
    memset(node, 0, sizeof(node));
    memset(sum, 0, sizeof sum);
    vector<pii> q;
    for(int i=1; i<=n; i++) { int a, s; cin >> a >> s; q.push_back({a, s}); }
    sort(q.begin(), q.end());
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> e;
    ll ans = 0;
    for(auto &r: q) {
        while(!e.empty()) {
            auto p = e.top();
            if(p.first > r.first) { break; }
            e.pop();
            update(1, m, 1, p.second, -1);
        }
        int k = query(1, m, 1);
        update(1, m, 1, k, 1);
        if(sum[k] <= r.first) { sum[k] = r.first + r.second; }
        else { sum[k] = sum[k] + r.second; }
        e.push({sum[k], k});
        ans = max(ans, sum[k]);
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