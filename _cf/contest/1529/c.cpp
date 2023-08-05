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

int t, n;
int h[100100], nx[200200], to[200200];
ll val[100100][2];
int cnt;

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

ll dp[100100][2];

void dfs(cint loc, cint fa) {
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa) {
            dfs(to[i], loc);
            dp[loc][0] += max(dp[to[i]][0]+abs(val[loc][0]-val[to[i]][0]), dp[to[i]][1]+abs(val[loc][0]-val[to[i]][1]));
            dp[loc][1] += max(dp[to[i]][0]+abs(val[loc][1]-val[to[i]][0]), dp[to[i]][1]+abs(val[loc][1]-val[to[i]][1]));
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int u, v;
        cin >> n;
        cnt = 0;
        for(int i=1; i<=n; i++) dp[i][0] = dp[i][1] = 0;
        for(int i=1; i<=n; i++) h[i] = 0;
        for(int i=1; i<=n; i++) cin >> val[i][0] >> val[i][1];
        for(int i=1; i<n; i++) {
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        dfs(1, 1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    return 0;
}