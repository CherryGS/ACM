#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
vector<int> to[200200];
int deg[200200];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        deg[v]++;
    }
    vector<int> ans;
    for(int i=1; i<=n; i++) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int r = q.top();
        q.pop();
        for(int v: to[r]) {
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
        ans.push_back(r);
    }
    if(ans.size() != n) cout << -1;
    else for(int v: ans) cout << v << ' ';
    cout << endl;
    return 0;
}