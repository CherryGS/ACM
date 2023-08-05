#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, s;
int h[100100], nx[100100], to[100100], cnt;
int vis[100100];

void add(cint f,cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void dfs(cint u, cint fa) {
    vis[u]++;
    for(int i=h[u]; i; i=nx[i])
        if(to[i] != fa && vis[to[i]] < 2 && to[i] != s) {
            dfs(to[i], u);
        }
}

int main() {
    cin >> n >> m >> s;
    ++s;
    int u, v;
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        ++u, ++v;
        add(v, u);
    }
    vector<int> ans;
    for(int i=h[s]; i; i=nx[i]) {
        if(vis[to[i]] < 2) dfs(to[i], to[i]);
        if(vis[to[i]] < 2) ans.push_back(to[i]);
        // cout << vis[to[i]] << " --- " << to[i] << endl;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int u: ans)
        cout << u-1 << endl;

    return 0;
}
/*

*/