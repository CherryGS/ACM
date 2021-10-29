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
int a[200100];
ll node[200200];
bool mp[200200];

int lowbit(cint x) { return x&-x; }

void add(int x) {
    while(x <= n) {
        ++node[x];
        x += lowbit(x);
    }
}

ll query(int x, int y) {
    if(x > y) return 0;
    ll ans = 0;
    while(y) {
        ans += node[y];
        y -= lowbit(y);
    }
    --x;
    while(x) {
        ans -= node[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin >> n;
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        // if(mp[a[i]+1]) { ++a[i]; }
        // mp[a[i]] = 1;
    }
    for(int i=1; i<=n; i++) {
        ans += query(a[i]+1, n);
        add(a[i]);
    }
    cout << ans << endl;

    return 0;
}