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
ll b[100100], a[100100];
bool mp[501][501];
int dis[501][501];
int num[100100];
vector<int> q[101];
int ans = inf_int;

int main() {
    int ct=0;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) if(b[i]) a[++ct] = b[i];
    n = ct;
    if(n > 500) cout << 3 << endl;
    else {
        for(int i=1; i<=n; i++) {
            for(int j=60; j>=0; j--) {
                if(a[i]&(1ll<<j)) q[j].push_back(i);
            }
        }
        for(int i=0; i<=60; i++) {
            int r = q[i].size();
            for(int j=1; j<r; j++) {
                for(int k=j-1; k>=0; k--) {
                    mp[q[i][j]][q[i][k]] = mp[q[i][k]][q[i][j]] = 1;
                }
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++) {
                if(mp[i][j]) dis[i][j] = dis[j][i] = 1;
                else dis[i][j] = dis[j][i] = inf_int;
            }
        int ans = inf_int;
        for(int k=1; k<=n; k++) {
            for(int i=1; i<k; i++)
                for(int j=1; j<i; j++) {
                    if(mp[i][k] && mp[k][j] && dis[i][j] < inf_int) ans = min(ans, dis[i][j] + 2);
                }
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++) {
                    if(dis[i][k] < inf_int && dis[k][j] < inf_int)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
        }
        if(ans == inf_int) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}