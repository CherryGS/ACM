#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
vector<int> to[200200];
const int e = 200001;
int p1, p2;

int dfs(cint loc, cint fa) {
    int s1 = 0;
    for(int v: to[loc])
        if(v != fa) {
            s1 += dfs(v, loc);
        }
    // cout << loc << "--------" << s1 << endl;
    if(loc != e) {
        if(s1 == 0) ++p1;
        else if(loc != 1) ++p2;
    }
    return s1 == 0;
}

int main() {
    cin >> t;
    to[e].push_back(1);
    while(t--) {
        cin >> n;
        int u, v;
        p1 = p2 = 0;
        for(int i=1; i<=n; i++) to[i].clear();
        for(int i=1; i<n; i++) {
            cin >> u >> v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs(e, e);
        // cout << p1 << "---" << p2 << endl;
        cout << p1 - p2 << endl;
    }
    return 0;
}