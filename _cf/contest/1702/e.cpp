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
bool flag = false;
bool vis[200200];
vector<int> to[200200];
int cnt;

void dfs(int u) {
    if(to[u].size() > 2) { flag = true; }
    vis[u] = 1;
    ++cnt;
    for(auto &v: to[u]) {
        if(flag == true) { return; }
        if(!vis[v]) { dfs(v); }
    }
}

void solve(cint T) {
    flag = false;
    cin >> n;
    int a, b;
    for(int i=1; i<=n; i++) { to[i].clear(); }
    for(int i=1; i<=n; i++) { vis[i] = 0; }
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cnt = 0;
            dfs(i);
            if(cnt % 2) { flag = true; break; }
        }
    }
    if(flag) { cout << "NO" << '\n'; }
    else { cout << "YES" << '\n'; }
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