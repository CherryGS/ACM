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

int n, k, m;
int a[100100];
int b[100100];
int sum[100100];
int num[100100];
bool vis[100100];
vector<int> to[100100];

bool dfs(int u, int l) {
    // cout << u << ' ' << l << endl;
    if(u == n) { return (l==k+1) || (l==k&&a[u]==b[l]); }
    bool flag = 0;
    if(l > k || a[u] != b[l]) { --sum[a[u]]; }
    else { flag = 1; }
    if(sum[a[u]] < num[a[u]]) { return false; }
    // cout << a[u] << ' ' << sum[a[u]] << ' ' << num[a[u]] << endl;
    for(int &v: to[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(dfs(v, l+flag) == false) { return false; }
            vis[v] = 0;
        }
    }
    if(!flag) { ++sum[a[u]]; }
    return true;
}

bool solve(cint T) {
    cin >> n >> m >> k;
    int u, v;
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=k; i++) { cin >> b[i]; }
    for(int i=1; i<=n; i++) { ++sum[a[i]]; }
    for(int i=1; i<=k; i++) { ++num[b[i]]; }
    vis[1] = 1;
    if(dfs(1, 1)) { cout << "Yes\n"; }
    else { cout << "No\n"; }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}