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
int dp[1<<20];
int fr[1<<20];
vector<int> ans[21];

struct node {
    int val;
    int id;
    void init(int i) { cin >> val; id = i; }
} a[200200], b[21];

int cacu(int r, int &x, int &now) {
    if(r <= 0) { return -1; }
    for(int i=(x+a[r].val-1)/a[r].val; i<=r; i=(x+a[r-i+1].val-1)/a[r-i+1].val) {
        if(1ll * a[r-i+1].val * i >= x) {
            return r-i;
        }
        if(r-i <= now) { break; }
    }
    return -1;
}

int dfs(int sit)  {
    if(dp[sit] >= -1) { return dp[sit]; }
    // cout << sit << " --- " << endl;
    int r;
    for(int i=0; (1<<i) <= sit; i++) {
        if((1<<i) & sit) {
            r = cacu(dfs(sit ^ (1<<i)), b[i+1].val, dp[sit]);
            if(r > dp[sit]) {
                dp[sit] = r;
                fr[sit] = i;
            }
        }
    }
    return dp[sit];
}

void solve(cint T) {
    cin >> n >> m;
    if(n < m) {
        cout << "NO\n";
        return;
    }
    for(int i=1; i<=n; i++) { a[i].init(i); }
    for(int i=1; i<=m; i++) { b[i].init(i); }
    sort(a+1, a+1+n, [](const node&a, const node&b) {
        return a.val < b.val;
    });
    sort(b+1, b+1+m, [](const node&a, const node&b) {
        return a.val > b.val;
    });
    memset(dp, -2, sizeof dp);
    dp[0] = n;
    int val = dfs((1<<m)-1);
    // for(int i=0; i<=(1<<m)-1; i++) { cout << dp[i] << ' '; }
    // cout << endl;
    if(val < 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        int r = (1<<m)-1, nx;
        while(r) {
            nx = r ^ (1<<fr[r]);
            for(int i=dp[r]+1; i<=dp[nx]; i++) {
                ans[b[fr[r]+1].id].push_back(a[i].id);
            }
            r = nx;
        }
        for(int i=1; i<=m; i++) {
            cout << ans[i].size() << ' ';
            for(auto &k: ans[i]) { cout << k << ' '; }
            cout << '\n';
        }
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
