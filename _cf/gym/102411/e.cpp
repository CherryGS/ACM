#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n, m;
int nx[400200], to[400200], he[400200], cnt;
bool book[200200];
int dp[200200];
int dep[200200];

inline void add(cint f, cint t) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t;
}

void dfs(cint fa, cint nod, cint d) {
    dep[nod] = i;
    for(int i = he[nod]; i; i = nx[i])
        if(to[i] != fa) {
            dfs(nod, to[i], d+1);
            dp[nod] += ((dp[to[i]] != 0) || book[to[i]]);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a,b;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    for(int i = 1; i <= m; i++) {
        cin >> a;
        book[a] = 1;
    }
    dfs(a, a, 1);
    if(dp[a] > 1) cout << "NO";
    return 0;
}