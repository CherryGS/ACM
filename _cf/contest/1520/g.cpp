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

int n, m, w;
int mp[2002][2002];
bool vis[2002][2002];
ll dis[2002][2002];

queue<pair<int, int> > q;
ll ans[3];

void bfs(cint x, cint y, bool st) {
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);
    while(!q.empty()) q.pop();
    q.push(make_pair(x, y));
    while(!q.empty()) {
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        if(st == 0 && dx == n && dy == m) ans[2] = dis[dx][dy];
        vis[dx][dy] = 1;
        if(mp[dx][dy] > 0) ans[st] = min(ans[st], dis[dx][dy]+mp[dx][dy]);
        if(dx > 1 && !vis[dx-1][dy] && mp[dx-1][dy] != -1) {
            vis[dx-1][dy] = 1;
            dis[dx-1][dy] = dis[dx][dy]+w;
            q.push(make_pair(dx-1,dy));
        }
        if(dx < n && !vis[dx+1][dy] && mp[dx+1][dy] != -1) {
            vis[dx+1][dy] = 1;
            dis[dx+1][dy] = dis[dx][dy]+w;
            q.push(make_pair(dx+1,dy));
        }
        if(dy > 1 && !vis[dx][dy-1] && mp[dx][dy-1] != -1) {
            vis[dx][dy-1] = 1;
            dis[dx][dy-1] = dis[dx][dy]+w;
            q.push(make_pair(dx,dy-1));
        }
        if(dy < m && !vis[dx][dy+1] && mp[dx][dy+1] != -1) {
            vis[dx][dy+1] = 1;
            dis[dx][dy+1] = dis[dx][dy]+w;
            q.push(make_pair(dx,dy+1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> w;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> mp[i][j];
    ans[0] = ans[1] = ans[2] = inf_ll;
    bfs(1, 1, 0);
    bfs(n, m, 1);
    // cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    if((ans[0] == inf_ll || ans[1] == inf_ll) && ans[2] == inf_ll) cout << -1 << endl;
    else if(ans[0] == inf_ll || ans[1] == inf_ll) cout << ans[2] << endl;
    else cout << min(ans[0]+ans[1], ans[2]) << endl;
    return 0;
}