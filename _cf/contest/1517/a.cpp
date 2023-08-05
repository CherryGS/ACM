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
ll n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll bs = 2050;
        int ans = 0;
        while(bs <= n) bs *= 10;
        bs /= 10;
        while(bs >= 2050 && n) {
            while(n >= bs) { n -= bs; ++ans;}
            bs /= 10;
        }
        if(n) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}