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

int n;
int h[100100], nx[200200], to[200200], w[200100], cnt;
int lim[100100][2]

void add(cint f, cint t, cint co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void dfs(cint loc, cint fa) {
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa) {
            dfs(to[i], loc);
        }
}

int tree[30][2];
bool flag[30][2];

int main() {
    int u, v, ww;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> lim[i][0] >> lim[i][1];
    for(int i=1; i<n; i++) {
        cin >> u >> v >> ww;
        add(u, v, ww);
        add(v, u, ww);
    }
    for(int i=30; )
    dfs(1, 1);
    return 0;
}