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

int t;
ll n, m;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(n > m) swap(n, m);
        ll ans = 0;
        for(ll i=n; i>=1; i--) {
            ans += i*(n-i+1)*(n-i+1);
        }
        ll tmp = 0;
        for(int i=1; i<=n; i++) {
            tmp += i*(n-i+1);
        }
        cout << ans+tmp*(m-n) << endl;
    }
    return 0;
}