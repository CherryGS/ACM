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
int cnt;
int c[200200];
int dfn[200200];
int edfn[200200];
int sum[200200];
ll ans[200200];
stack<int> st[200200];
vector<int> to[200200];

void dfs(int u, int fa) {
    dfn[u] = ++cnt;
    if(u != 0) { st[c[u]].push(u); }
    ll sum = 0;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u);
        }
    }
    edfn[u] = cnt;
    sum += edfn[u] - dfn[u];
    ans[c[u]] += sum * (sum-1) / 2;
}

bool cmp(cint x, cint y) {
    return dfn[x] < dfn[y];
}

void solve(cint T) {
    cnt = 0;
    cin >> n;
    for(int i=1; i<=n; i++) { to[i].clear(); ans[i] = 0; }
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    for(int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    to[0].push_back(1);
    dfs(0, 0);
    ll ans = 0;
}

void init() {
    for(int i=1; i<=100000; i++) { st[i].push(0); }
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