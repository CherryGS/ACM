#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
bool vis[200100];
vector<int> to[200200];
int deg[200200];
int fa[200200];

void dfs(cint u, cint ff) {
    for(int v: to[u]) {
        if(v != ff && v >= n) dfs(v, u);
        fa[v] = u;
    }
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m+n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> q;
    for(int i=0; i<n+m; i++) if(deg[i] == 1) q.push(i);
    // cout << q.size() << endl;
    for(int i=0; i<n; i++) { dfs(i, i); }
    int ans = 0;
    while(!q.empty()) {
        int r = q.front();
        q.pop();
        if(vis[r] == 0) { if(vis[fa[r]] == 0) { ++ans; } vis[fa[r]] = 1; }
        for(int v: to[r]) {
            deg[v]--;
            if(deg[v] == 1) q.push(v);
        }
    }
    // cout << ans << endl;
    int st = -1;
    for(int i=0; i<n; i++) {
        if(vis[i]) { st = i; break; }
    }
    // cout << st << endl;
    if(st == -1) {
        st = 0;
        vis[0] = 1;
        ++ans;
    }
    bool rr = 1;
    for(int i=st; i<n; i++) {
        if(vis[i]) rr = 1;
        else {
            if(rr == 1) rr = 0;
            else {
                vis[i] = 1;
                ++ans;
                rr = 1;
            }
        }
    }
    rr = 1;
    for(int i=st; i>=0; i--) {
        if(vis[i]) rr = 1;
        else {
            if(rr == 1) rr = 0;
            else {
                vis[i] = 1;
                ++ans;
                rr = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}