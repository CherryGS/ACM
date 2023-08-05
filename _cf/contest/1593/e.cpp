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

int t;
int n, k;
vector<int> to[400400];
int deg[400400];
bool vis[400400];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int ans = 0;
        for(int i=1; i<=n; i++) to[i].clear();
        for(int i=1; i<=n; i++) deg[i] = 0;
        for(int i=1; i<=n; i++) vis[i] = 0;
        for(int i=1; i<n; i++) {
            int u, v;
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        queue<int> q;
        for(int i=1; i<=n; i++) if(deg[i] == 1) q.push(i);
        if(!q.empty()) q.push(inf_int);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == inf_int) {
                --k;
                if(q.empty() || !k) break;
                u = q.front();
                q.pop();
                q.push(inf_int);
            }
            if(u != inf_int) vis[u] = 1;
            for(int v: to[u]) {
                deg[v]--;
                if(deg[v] == 1) q.push(v);
            }
        }
        for(int i=1; i<=n; i++) if(!vis[i]) ++ans;
        if(n == 1 && k) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
/*
1
1 1

*/