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

typedef pair<ll, int> pii;
int n, m, s;
int h[200200], nx[500200], to[500200], cnt;
ll w[500200];
ll dis[200200];

void add(cint f, cint t, ll co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

priority_queue<pii, vector<pii>, greater<pii> > q;

void dij() {
    q.push({0, s});
    dis[s] = 0;
    while(!q.empty()) {
        int s = q.top().second;
        q.pop();
        for(int i=h[s]; i; i=nx[i]) {
            if(dis[to[i]] > dis[s]+w[i]) {
                dis[to[i]] = dis[s]+w[i];
                q.push({dis[to[i]], to[i]});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    int u, v;
    ll W;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> W;
        add(u, v, W);
    }
    for(int i=1; i<=n; i++) dis[i] = (1ll<<31)-1;
    dij();
    for(int i=1; i<=n; i++) cout << dis[i] << ' ';
    cout << endl;
    return 0;
}
/*
2 1
1 2 1
*/