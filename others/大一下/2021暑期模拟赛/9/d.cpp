#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
ll val[200200], tar[200200];
vector<int> to[200200];
bool vis[200200];
bool col[200200];
bool flag;

void dfs(cint u) {
    vis[u] = 1;
    for(int v:to[u]) {
        if(!vis[v]) {
            col[v] = col[u]^1;
            dfs(v);
            val[u] -= val[v];
        }
        else if(col[v] == col[u]) flag = 1;
    }
    // cout << u << '+' << val[u] << endl;
}

int main() {
    cin >> t;
    while(t--) {
        flag = 0;
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> val[i];
        for(int i=1; i<=n; i++) cin >> tar[i], val[i] = -tar[i]+val[i];
        for(int i=1; i<=n; i++) vis[i] = col[i] = 0;
        for(int i=1; i<=n; i++) to[i].clear();
        int u, v;
        for(int i=1; i<=m; i++) {
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs(1);
        if(!val[1] || (!(val[1]&1) && flag)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
    return 0;
}