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

int t, n;
ll c[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> c[i];
        ll sum1 = 0, mx1 = inf_int, sum2 = 0, mx2 = inf_int;
        ll ans = inf_ll;
        for(int i=1; i<=n; i++) {
            if(i&1) {
                sum1 += c[i];
                mx1 = min(mx1, c[i]);
            } else {
                sum2 += c[i];
                mx2 = min(mx2, c[i]);
            }
            ans = min(ans, sum1+sum2+mx1*(n-(i+1)/2)+mx2*(n-i/2));
        }
        cout << ans << endl;
    }
    return 0;
}