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

int n, s, t;
vector<int> edge[500001];
vector<int> q[2];
int dep[500100];
int fa[500100];
int mx_le[500100];
int rt;

void dfs(cint u, cint fa) {
    for(int v:edge[u])
        if(v != fa) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            if(v != s && v != t) {
                dfs(v, u);
                mx_le[u] = max(mx_le[u], mx_le[v]+1);
            }
        }
}

int main() {
    cin >> n >> s >> t;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        edge[v].push_back(u);
        edge[u].push_back(v);
    }
    if(n == 2) {

    } else {
        for(int i=1; i<=n; i++)
            if(i != u && i != v) rt = i;
        fa[rt] = rt;
        dfs(rt, rt);
        dfs(s, fa[s]);
        dfs(t, fa[t]);
        for(int i=s; i!=rt; i=fa[i]) q[0].push_back(i);
        for(int i=t; i!=rt; i=fa[i]) q[1].push_back(i);
        q[0].push_back(rt);
        for(int i=q[1].size(); i; i--) q[0].push_back(q[1][i-1]);
        int le = q[0].size();
        int l = le-2, r = le - 1;
        int ans = inf_int;
        while(l >= 0) {
            ans = (l+mx_le(q[0][l])) - (le-r+mx_le[q[0][r]]);
            if(l+mx_le(q[0][l]) >= le-r+mx_le[q[0][r]]) {
                if(r-l == 1) {
                    if(r >= ceil(le/2)) --l; --r;
                    else break;
                }
            }
        }
    }
    return 0;
}