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
int ans[100100], cnt;

int gcd(cint x, cint y) {
    return y == 0? x: gcd(y, x%y);
}

int main() {
    ll tmp = 1;
    ans[++cnt] = 1;
    cin >> n;
    for(int i=2; i<=n; i++) {
        if(gcd(n, i) == 1) {
            ans[++cnt] = i;
            tmp = (tmp*i) % n;
        }
    }
    if(tmp == 1) {
        cout << cnt << endl;
    } else cout << cnt-1 << endl;
    for(int i=1; i<=cnt; i++) {
        if(ans[i] != tmp || tmp == 1) cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}