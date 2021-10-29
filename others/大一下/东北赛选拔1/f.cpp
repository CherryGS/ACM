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
ll to[1010], num[1010], cnt;

int main() {
    ll ans = 1;
    cin >> n;
    for(int i=2; i<=n; i++) {
        int r = i;
        for(int j=2; j<=r; j++) {
            while(!(r%j)) {
                if(!to[j]) {
                    to[j] = ++cnt;
                }
                ++num[to[j]];
                r /= j;
            }
        }
    }
    for(int i=1; i<=cnt; i++) ans = (ans*(num[i]+1)) % mod;
    cout << ans << endl;
    return 0;
}