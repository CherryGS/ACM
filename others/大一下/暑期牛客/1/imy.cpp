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

int n;
int p[5050];
int pre[5050][5050]; // j~n bigger than p[i]
ll f[5050][5050];
ll g[5050][5050];
int inv[5050];


int main() {
    cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=0; i<=n; i++) {
        for(int j=n; j>i; j--) {
            if(p[i] < p[j]) ++pre[i][j];
            pre[i][j] += pre[i][j+1];
        }
    }
    int ans = 0;
    g[0][0] = 1;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(g[i][j]) {
                if(p[i] > p[j]) {
                    f[i][j] = (f[i][j] + g[i][j]*inv[pre[j][i]]) % mod;
                    // cout << i << "---" << j << "---" << f[i][j] << ' ' << g[i][j] << inv[pre[]] << endl;
                    ans = (ans + g[i][j]*inv[pre[j][i]]) % mod;
                }
            }
            if(f[i][j]) {
                if(p[j] > p[i]) {
                    g[i][j] = (g[i][j] + f[i][j]*inv[pre[i][j]]) % mod;
                    ans = (ans + f[i][j]*inv[pre[i][j]]) % mod;
                }
            }
            f[i][j+1] = (f[i][j+1] + f[i][j]) % mod;
            g[i+1][j] = (g[i+1][j] + g[i][j]) % mod;
            cout << f[i][j] << ' ' << g[i][j] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}