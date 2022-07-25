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
int a[200200];
vector<int> to[200200];
set<int> e[200200];
int id[200200];
int ans;

void dfs(int u, int fa) {
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u);
        }
    }
    e[u].insert(a[u]);
    bool flag = false;
    for(int &v: to[u]) {
        if(v != fa) {
            if(flag == false) {
                for(auto &k: e[id[v]]) {
                    if(e[id[u]].find(k) != e[id[u]].end()) { ++ans; e[id[u]].clear(); flag = true; break; }
                }
                if(flag == false) {
                    if(e[id[u]].size() < e[id[v]].size()) { swap(id[u], id[v]); }
                    for(auto &k: e[id[v]]) {
                        e[id[u]].insert(k ^ a[u]);
                    }
                }
            }
            e[v].clear();
        }
    }
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) { id[i] = i; }
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 1);
    cout << ans << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}