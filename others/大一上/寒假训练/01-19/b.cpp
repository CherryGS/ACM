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

int n, m;
int bcj[200200];
int sum[200200];

inline int fd(cint x) {
    return bcj[x] == x? x: bcj[x]=fd(bcj[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int aa, bb;
    for(int i=1; i<=n; i++) bcj[i]=i;
    for(int i=1; i<=m; i++) {
        cin >> aa >> bb;
        if(aa > bb) swap(aa, bb);
        bcj[fd(bb)] = fd(aa);
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        ++sum[fd(i)];
        ans = max(ans, sum[fd(i)]);
    }
    cout << ans << endl;
    return 0;
}