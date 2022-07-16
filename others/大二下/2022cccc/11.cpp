#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, m;
int fa[100100];
int dep[100100];
bool vis[100100];
ll ans = 0;

void dfs(int x) {
    if(fa[x] == -1) { dep[x] = 1; return; }
    if(vis[fa[x]]) {
        ans ++;
        dep[x] = dep[fa[x]] + 1;
        return;
    }
    else {
        vis[fa[x]] = 1;
        ans += 2;
        dfs(fa[x]);
        dep[x] = dep[fa[x]] + 1;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> fa[i]; if(fa[i] == -1) { dep[i] = 1; } }
    int x;
    int mx = 0;
    for(int i=1; i<=m; i++) {
        cin >> x;
        if(!vis[x]) { vis[x] = 1; ans++; }
        else {
            cout << ans - mx << endl;
            continue;
        }
        dfs(x);
        mx = max(mx, dep[x]);
        cout << ans - mx << endl;
    }
    // cout << dep[3] << endl;
}