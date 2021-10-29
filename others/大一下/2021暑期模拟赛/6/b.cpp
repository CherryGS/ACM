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

#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

typedef long long ll;
const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
vector<int> to[2002];
bool vis[2002];
ll ans[2];
ll pre[2002][2];
int c[2002];
int num[2002], cnt;

void init() {
    pre[0][0] = pre[0][1] = 1;
    for(int i=1; i<=2000; i++) {
        pre[i][0] = (pre[i-1][0] * 19560929ll) % (ll)(1e9+7);
        pre[i][1] = (pre[i-1][1] * 19560929ll) % (ll)(1e9+9);
    }
}

void dfs(cint loc) {
    // cout << loc << ' ' << cnt << endl;
    vis[loc] = 1;
    num[c[loc]]++;
    ans[0] = (ans[0] + pre[loc-1][0]*cnt) % (ll)(1e9+7);
    ans[1] = (ans[1] + pre[loc-1][1]*cnt) % (ll)(1e9+9);
    for(int v: to[loc])
        if(!vis[v]) {
            if(!num[c[v]]) {
                ++cnt;
            }
            dfs(v);
        }
    num[c[loc]]--;
    if(!num[c[loc]]) --cnt;
}

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) to[i].clear();
        int tmp;
        for(int i=2; i<=n; i++) {
            cin >> tmp;
            to[i].push_back(tmp);
            to[tmp].push_back(i);
        }
        for(int i=1; i<=n; i++) cin >> c[i];

        for(int i=1; i<=n; i++) {
            memset(vis, 0, sizeof vis);
            memset(num, 0, sizeof num);
            ans[0] = ans[1] = 0;
            cnt = 1;
            dfs(i);
            cout << ans[0] << ' ' << ans[1] << endl;
        }
    }
    return 0;
}