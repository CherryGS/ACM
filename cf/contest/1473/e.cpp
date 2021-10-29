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
int n, m;
int h[200200], nx[400200], to[400200], cnt;
ll w[400200];
ll dis[200200][4];

void add(cint f, cint t, ll co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

priority_queue<pii, vector<pii>, greater<pii> > q;

void dij(cint loc, cint st) {
    if(st == 0) q.push({dis[1][loc], 1});
    else for(int i=1; i<=n; i++) if(dis[i][loc] < dis[0][0]) q.push({dis[i][loc], i});
    while(!q.empty()) {
        int s = q.top().second;
        q.pop();
        for(int i=h[s]; i; i=nx[i]) {
            if(dis[to[i]][loc] > dis[s][loc]+w[i]) {
                dis[to[i]][loc] = dis[s][loc]+w[i];
                q.push({dis[to[i]][loc], to[i]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v;
    ll W;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> W;
        add(u, v, W);
        add(v, u, W);
    }
    memset(dis, 0x7f, sizeof dis);
    dis[1][0] = 0;
    dij(0, 0);
    for(int i=1; i<=n; i++) {
        for(int j=h[i]; j; j=nx[j]) {
            // if(to[j] == 4) cout << dis[i][0] << "---" << i << endl;
            if(dis[i][0] < dis[0][0]) {
                dis[to[j]][1] = min(dis[to[j]][1], dis[i][0]);
                dis[to[j]][2] = min(dis[to[j]][2], dis[i][0] + w[j]*(ll)2);
            }
        }
    }
    dis[1][0] = dis[0][0];
    dij(1, 1);
    dij(2, 1);
    for(int i=1; i<=n; i++) {
        for(int j=h[i]; j; j=nx[j]) {
            dis[to[j]][3] = min(dis[to[j]][3], dis[i][1]+w[j]*(ll)2);
            dis[to[j]][3] = min(dis[to[j]][3], dis[i][2]);
            // if(to[j] == 2) cout << dis[i][1]+w[j]*2 << ' ' << w[j] << ' ' << dis[i][2] << ' ' << i << endl;
        }
    }
    dij(3, 1);
    // cout << dis[3][3] << '+' << endl;
    for(int i=2; i<=n; i++) cout << dis[i][3] << ' ';
    cout << endl;
    return 0;
}
/*
4 4
1 2 9
2 3 2
2 4 7
3 4 6


*/