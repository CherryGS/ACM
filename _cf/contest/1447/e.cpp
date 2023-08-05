#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[200100];

int dfs(cint l, cint r, cint num, int key) {
    if(l > r) return 0;
    if(l == r) return 1;
    int k = lower_bound(a+1, a+1+n, key+(1<<num)) - a;
    int x = dfs(l, k-1, num-1, key);
    int y = dfs(k, r, num-1, key+(1<<num));
    if(!(x*y)) return max(x, y);
    return max(x,y) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int t=0;
    while((1<<t) <= a[n]) ++t;
    cout << n-dfs(1, n, t-1, 0);
    return 0;
}