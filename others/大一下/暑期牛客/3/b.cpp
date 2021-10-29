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

const int mx = 5000*5000;
ll n, m, a, b, c, d, p;
int bcj[10010];
int sum[10010];

struct node {
    int x, y;
    ll va;
    bool operator < (const node&a) const {
        return va < a.va;
    }
    void init(cint xx, cint yy, ll zz) {
        x = xx;
        y = yy;
        va = zz;
    }
} s[mx+1];

int fd(cint x) {
    return bcj[x] == x ? x : bcj[x] = fd(bcj[x]);
}

// void debug() {
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m; j++) {
//             cout << val[m*(i-1)+j] << ' ';
//         } 
//         cout << endl;
//     }
// }

int main() {
    cin >> n >> m >> a >> b >> c >> d >> p;
    ll tmp = a;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            tmp = ((tmp*tmp)%p*b+tmp*c+d) % p;
            s[m*(i-1)+j].init(i, j, tmp);
        }
    }
    sort(s+1, s+n*m+1);
    for(int i=1; i<=n+m; i++) {
        sum[i] = 1;
        bcj[i] = i;
    }
    ll ans = 0;
    for(int i=1; i<=n*m; i++) {
        int x = fd(s[i].x);
        int y = fd(s[i].y+n);
        if(x != y) {
            sum[x] += sum[y];
            bcj[y] = x;
            ans += s[i].va;
            if(sum[x] == n+m) break;
        }
    }
    // debug();
    cout << ans << endl;
    return 0;
}
/*
1 5000 1 1 1 1 100000
*/