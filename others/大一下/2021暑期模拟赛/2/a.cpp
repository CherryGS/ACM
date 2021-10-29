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

const int mx_n = 10000000;
ll t, n;
bool vis[mx_n+1];
int pri[1001000], cnt;
ll sum[1001000];

void init() {
    vis[0] = vis[1] = 1;
    for(int i=2; i<=mx_n; i++) {
        if(!vis[i]) {
            pri[++cnt] = i;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll * pri[j] * i > mx_n) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]) {

            } else {
                break;
            }
        }
    }
    for(int i=1; i<=cnt; i++)
        sum[i] = sum[i-1] + pri[i];
}

int main() {
    init();
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = (n+1)*(n)/2-3;
        for(int i=2; i<=cnt; i++) {
            if(pri[i] > n) break;
            ans -= pri[i];
            ans += 2*pri[i];
        }
        cout << ans << endl;
    }
    return 0;
}