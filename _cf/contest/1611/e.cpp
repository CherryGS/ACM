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
bool pe[200200];
vector<int> to[200200];
int tim[200200];
int ans;

void dfs(cint u, cint fa) {
    for(int v: to[u])
        if(v != fa) dfs(v, u);
    if(pe[u]) tim[u] = 0;
    else tim[u] = hf_int;
    for(int v: to[u])
        if(v != fa) tim[u] = min(tim[u], tim[v]+1);
    // cout << u << ' ' << fa << ' ' << tim[u] << endl;
}

bool check(cint u, cint fa, cint step) {
    if(tim[u] <= step) { ++ans; return 0; }
    if(to[u].size() == 1 && u != 1) return 1;
    bool flag = 0;
    for(int v: to[u])
        if(v != fa) flag |= check(v, u, step+1);
    return flag;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> k;
        ans = 0;
        for(int i=1; i<=n; i++)
            pe[i] = 0;
        for(int i=1; i<=k; i++) {
            int tmp;
            cin >> tmp;
            pe[tmp] = 1;
        }
        int u, v;
        for(int i=1; i<=n; i++)
            to[i].clear();
        for(int i=1; i<n; i++) {
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs(1, 1);
        if(check(1, 1, 0)) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}