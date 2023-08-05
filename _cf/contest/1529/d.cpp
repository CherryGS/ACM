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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int to[1001000];
bool vis[1001000];

ll ans[1001000];
ll pre[1001000];
int n;

void init() {
    for(int i=2; i<=1000000; i++) if(!vis[i])
        for(int j=1; i*j<=1000000; j++) {
            vis[i*j] = 1;
            to[i*j] = i;
        }
}

ll sol(int x) {
    int tmp = 0, la = 0;
    ll ans = 1;
    while(x) {
        if(to[x] != la) {
            ans *= (tmp+1);
            tmp = 0;
            la = to[x];
        }
        if(x == 1) break;
        x /= la;
        ++tmp;
    }
    return ans;
}

int main() {
    init();
    cin >> n;
    for(int i=1; i<=n; i++) {
        ans[i] = (pre[i-1]+sol(i)) % mod;
        pre[i] = (pre[i-1]+ans[i]) % mod;
    }
    cout << ans[n] << endl;
    return 0;
}