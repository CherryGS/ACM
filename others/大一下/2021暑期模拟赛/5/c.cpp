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

typedef pair<ll,int> pli;
int n, m;
ll c, d, e; 
vector<int> to[100100], co[100100];
ll dis[100100];
int lim[100100];
bool flag;

struct node {
    int val, he;
    bool operator < (const node&a) const {
        return val > a.val;
    } 
};

priority_queue<node, vector<node> >q;

void dij() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()) {
        int k = q.top().val;
        int s = q.top().he;
        int r = lim[s];
        if(s == n) flag = 1;
        q.pop();
        for(int i=0; i<to[s].size(); i++) {
            if(r == 0) {
                ++k;
                r = e;
            }
            int w = co[s][i]/d;
            if(d*w < co[s][i]) ++w;
            if(dis[to[s][i]] > max(k, w)) { dis[to[s][i]] = max(k, w); lim[to[s][i]] = r-1; q.push({max(k, w), to[s][i]}); }
            else if(dis[to[s][i]] == max(k, w) && lim[to[s][i]] < r-1) { lim[to[s][i]] = r-1; }
        }
    }
    if(flag) cout << dis[n]*c << endl;
    else cout << -1 << endl;
}

int main() {
    cin >> n >> m;
    cin >> c >> d >> e;
    int u, v, w;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        to[u].push_back(v);
        to[v].push_back(u);
        co[u].push_back(w);
        co[v].push_back(w);
    }
    dij();
    return 0;
}