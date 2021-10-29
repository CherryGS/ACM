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
ll b[100100], c[100100];
ll st[32];

void debug() {
    for(int i=0; i<31; i++)
        cout << st[i] << ' ';
        cout << endl;
}

int main() {
    cin >> n;
    for(int i=2; i<=n; i++) cin >> b[i];
    for(int i=2; i<=n; i++) cin >> c[i], c[i] -= b[i];
    for(int i=0; i<=31; i++) {
        bool r = 0;
        for(int j=2; j<=n; j++) {
            if(r == 0) {
                if((1ll<<i)&c[j]) break;
                else if((1ll<<i)&b[j]) r = 1;
            }
            else {
                if(!((1ll<<i)&b[j])) break;
                else if(!((1ll<<i)&c[j])) r = 0;
            }
            if(j == n) ++st[i];
        }
        r = 1;
        for(int j=2; j<=n; j++) {
            if(r == 0) {
                if((1ll<<i)&c[j]) break;
                else if((1ll<<i)&b[j]) r = 1;
            }
            else {
                if(!((1ll<<i)&b[j])) break;
                else if(!((1ll<<i)&c[j])) r = 0;
            }
            if(j == n) ++st[i];            
        }
    }
    // debug();
    ll ans = 1;
    for(int i=0; i<=31; i++)
        ans = (ans * st[i]);
    cout << ans << endl;
    return 0;
}