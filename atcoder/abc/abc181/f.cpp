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
const int inf_int = 0x7fffffff;
const double ept = 1e-9;

int n, min_x, max_x;
bool dp[1001][101];

struct Node {
    int x, y;
    void init() {
        cin >> x >> y;
        y <<= 1;
        x <<= 1;
    }
    bool operator < (const Node&a) const {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
}a[1010];

bool check(double r) {
    memset(dp, 0, sizeof dp);
    int bs_x, bs_y=100;
    bs_x = int(r-min_x+1);
    for(int i=0; )
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) a[i].init();
    sort(a+1, a+1+n);
    min_x = a[1].x, max_x = a[n].x;
    double l = 0, r = 200, mid;
    while(r-l > ept) {
        mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << mid/2;
    return 0;
}