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

int n, m, k;
int a[40400], b[40400];
int sum[40400][2];

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
    int r = 1;
    for(int i=1; i<=n+1; i++) {
        if(a[i]) ++ r;
        if(i != 1) {
            if(!a[i] && r) {
                ++sum[r][0];
                r = 0;
            }
        }
    }
    r = 0;
    for(int i=1; i<=m+1; i++) {
        if(b[i]) ++ r;
        if(i != 1) {
            if(!b[i] && r) {
                ++sum[r][1];
                r = 0;
            }
        }
    }
    int p1 = 0, p2 = 0;
    for(int i=n; i>=1; i--) {
        p1 += p2;
        if(sum[i][0]) {
            ++p1;
            ++p2;
        }
        sum[i][0] += p1;
    }
    p1 = 0, p2 = 0;
    for(int i=m; i>=1; i--) {
        p1 += p2;
        if(sum[i][1]) {
            ++p1;
            ++p2;
        }
        sum[i][1] += p1;
    }
    ll ans = 0;
    for(int i=1; i<=k; i++)
        if(!(k%i)) {
            ans += sum[i][0] * sum[k/i][1];
        }
    cout << ans << endl;

    return 0;
}