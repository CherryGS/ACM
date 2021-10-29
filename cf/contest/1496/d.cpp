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

int n, dis, ans;
int a[100100];

int dfs(cint loc, cint step) {
    if(a[loc] < a[loc+step] || loc+step > n || loc+step < 1) return 1;
    else return dfs(loc+step, step)+1;
}

void check(int l, int r) {
    if(l > r) swap(l, r);
    --l; --r;
    // cerr << l << ' ' << r << endl;
    if(dis <= r) ans = 0;
    if(dis >= r) return;
    dis = r;
    if(l == r && !(r&1)) ++ans;
    if(!(r & 1) && r-l == 1 && l != 1) ++ans;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        if((a[i] > a[i-1] || i == 1) && (a[i] > a[i+1] || i == n)) {
            check(dfs(i, 1), dfs(i, -1));
        }
    }
    cout << ans << endl;
    return 0;
}