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

int h[10010], nx[20020], to[20020], cnt;
bool flag[10010];

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

int n, mx;
int pth[10010], ct;
int ans[10010];

void sol() {
    bool now = 0;
    for(int i=1; i<=ct; i++)
        if(ans[i] > pth[i]) { now = 1; break;}
        else if(ans[i] < pth[i]) { return; }
    for(int i=1; i<=ct; i++) ans[i] = pth[i];
}

void dfs(cint loc, cint le) {
    if(!h[loc]) {
        if(le >= mx) sol();
        mx = max(mx, le);
        return;
    }
    for(int i=h[loc]; i; i=nx[i]) {
        // cout << loc << ' ' << to[i] << "---" << ct << endl;
        pth[++ct] = to[i];
        dfs(to[i], le+1);
        --ct;
    }
}

int main() {
    int k, r;
    cin >> n;
    for(int i=0; i<=n-1; i++) {
        ans[i] = inf_int;
        cin >> k;
        for(int j=1; j<=k; j++) {
            cin >> r;
            add(i, r);
            flag[r] = 1;
        }
    }
    int s;
    for(int i=0; i<=n-1; i++) 
        if(!flag[i]) {
            s = i;
            break;
        }
    pth[++ct] = s;
    dfs(s, 1);
    cout << mx << endl;
    for(int i=1; i<=mx; i++) {
        cout << ans[i];
        if(i != mx) cout << ' ';
    }
    cout << endl;
    return 0;
}