#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int bs = 505;

int nx[10100], to[10100], he[1010], cnt;
bool vis[1010];
int pre[1010];
int tx[1010], ty[1010];

bool dfs(int loc) {
    for(int i=he[loc]; i; i = nx[i])
        if(!vis[to[i]]) {
            vis[to[i]] = 1;
            if(!pre[to[i]] || dfs(pre[to[i]])) {
                pre[to[i]] = loc;
                return 1;
            }
        }
    return 0;
}

void add(cint f, cint t) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t; 
}

int n;

int main() {
    cin >> n;
    int a, b, ans=0;
    for(int i=1; i<=n; i++) cin >> tx[i] >> ty[i];
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        for(int j=1; j<=n; j++)
            if(tx[j]<a && ty[j]<b) {
                add(j,i+bs);
                add(i+bs,j);
            }
    }
    for(int i=1; i<=n; i++) {   
        memset(vis, 0, sizeof vis);
        ans += dfs(i);
    }
    cout << ans;
    return 0;
}