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

int n;
int l[1000100];
int r[1000100];
int st[1000100], cnt;
vector<int> to[1000100];

struct node {
    int l, r, id;
    bool operator < (const node&a) const {
        return l == a.l ? r > a.r : l < a.l;
    }
};

vector<int> del[1000100];
ll dp[1000100];
ll f[1000100];
ll inv[1000100];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod1; }
        bs = bs * bs % mod1;
        x >>= 1;
    }
    return ans;
}

void init() {
    int mx = 1000000;
    f[0] = 1;
    for(int i=1; i<=mx; i++) { f[i] = f[i-1] * i % mod1; }
    inv[mx] = ksm(f[mx], mod1-2);
    for(int i=mx-1; i>=0; i--) { inv[i] = inv[i+1] * (i+1) % mod1; }
}

ll C(int n, int m) {
    return f[n] * inv[m] % mod1 * inv[n-m] % mod1;
}

void dfs(int u, int fa) {
    ll sum = 0;
    for(int &v: to[u]) {
        if(v != fa) {
            sum += r[v] - l[v] + 1;
        }
    }
    dp[u] = r[u] - l[u] + 1 - sum;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u);
            dp[u] = dp[u] * dp[v] * C(sum, r[v]-l[v]+1);
            sum -= r[v]-l[v]+1;
        }
    }
}

void solve(cint T) {
    cnt = 0;
    n = 0;
    cin >> n;
    if(n == 0) { return; }
    l[0] = 1;
    for(int i=1; i<=n; i++) { dp[i] = 0; to[i].clear(); }
    for(int i=1; i<=n; i++) { del[i].clear(); }
    for(int i=1; i<=n; i++) { cin >> l[i]; }
    for(int i=1; i<=n; i++) { cin >> r[i]; }
    vector<node> q;
    for(int i=1; i<=n; i++) { q.push_back({l[i], r[i], i}); }
    sort(q.begin(), q.end());
    for(auto &k: q) {
        cout << k.l << ' ' << k.r << ' ' << k.id << endl;
    }
    int l = 0;
    bool flag = false;
    for(int i=1; i<=n; i++) {
        while(l < n && q[l].l <= i) {
            del[q[l].r].push_back(q[l].id);
            st[++cnt] = q[l].id;
            ++l;
        }
        cout << i << ' ' << del[i].size() << endl;
        for(int j=del[i].size()-1; j>=0; j--) {
            for(int k=1; k<=10; k++) { cout << st[i] << ' '; }
            cout << endl;
            cout << cnt << ' ' << st[cnt] << ' ' << del[i][j] << ' ' << j << ' ' << del[i].size() << ' ' << i << endl;
            if(st[cnt] != del[i][j]) { flag = true; break; }
            to[st[cnt]].push_back(st[cnt-1]);
            to[st[cnt-1]].push_back(st[cnt]);
            --cnt;
        }
        if(flag == true) { break; }
    }
    dfs(0, 0);
    cout << flag << endl;
    if(flag == true) { dp[0] = 0; }
    cout << "Case #" << T << ": " << dp[0] << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1000;
    //std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}