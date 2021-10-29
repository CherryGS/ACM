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

int n, m, k;
int b[2002], c[2002];
bool vis[2020];
bool mp[2020][2020];

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) cin >> c[i];
    int x, y;
    for(int i=1; i<=n; i++) {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(!vis[j] && mp[i][j] && b[i] == c[j]) {
                vis[j] = 1;
                ans += c[j];
                break;
            }
        }
    }
    return 0;
}