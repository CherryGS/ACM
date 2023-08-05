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
int n;
ll d[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> d[i];
        sort(d+1, d+1+n);
        ll ans = 0;
        ll pre = 0;
        for(int i=2; i<=n; i++) {
            pre += (i-1)*(d[i]-d[i-1]);
            ans -= pre-(d[i]-d[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}