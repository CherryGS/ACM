#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll t, n, k;
bool vis[10];

int main() {
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof vis);
        cin >> n >> k;
        ll pre = 0, ans = inf_ll;
        for(ll i=1e9; i; i/=10) {
            if(i <= n) {
                ll r = n/i;
                pre += r*i;
                n %= i;
                if(!vis[i]) {
                    vis[i] = 1;
                    --k;
                }
                if(k == 2) {
                    
                }
            }
        }
    }
    return 0;
}