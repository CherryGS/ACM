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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int dfn[100100], edfn[100100], cnt;
int sum[320][10001];
vector<int> to[100100];
set<int> e[100100];
int siz;

void dfs(int u, int fa) {
    dfn[u] = ++cnt;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u);
        }
    }
    edfn[u] = cnt;
}

void update(int x, int y) {
    // cout << x << ' ' << y << ' ' << dfn[x]/siz << ' ' << dfn[x] << endl;
    if(e[dfn[x]].find(y) == e[dfn[x]].end()) {
        ++sum[dfn[x]/siz][y];
        e[dfn[x]].insert(y);
    }
}

int query(int x, int y) {
    int l = dfn[x], r = edfn[x];
    int dl = (l+siz-1)/siz, dr = (r+1)/siz-1;
    int ans = 0;
    if(dl <= dr) {
        for(int i=dl; i<=dr; i++) { ans += sum[i][y]; }
        for(int i=l; i<dl*siz; i++) { ans += e[i].count(y); }
        // cout << siz << " " << l << ' ' << r << ' ' << dl << ' ' << dr << ' ' << ans << endl;
        for(int i=(dr+1)*siz; i<=r; i++) { ans += e[i].count(y); }
    }
    else {
        for(int i=l; i<=r; i++) { ans += e[i].count(y); }
    }
    return ans;
}

bool solve(cint T) {
    cin >> n;
    siz = sqrt(n);
    int u;
    for(int i=2; i<=n; i++) {
        cin >> u;
        to[u].push_back(i);
        to[i].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    int r, x, y;
    for(int i=1; i<=m; i++) {
        cin >> r >> x >> y;
        if(r == 1) { update(x, y); }
        else { cout << query(x, y) << '\n'; }
    }
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}