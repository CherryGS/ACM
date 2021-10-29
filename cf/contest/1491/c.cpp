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
int n;
int a[5050];
int r[5050];

int lowbit(cint x) { return x&-x; }

void add_p(int loc, cint num) {
    while(loc <= n) {
        r[loc] += num;
        loc = loc + lowbit(loc);
    }
}

int get_r(int x) {
    // 1~x
    int ans = 0;
    while(x) {
        ans += r[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i], r[i] = 0;
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            int s = get_r(i);
            // cout << i << ' ' << a[i] << ' ' << s << endl;
            if(a[i] - s >= 1) {
                ans += a[i]-s-1;
            } else {
                add_p(i+1, s-a[i]+1);
                add_p(i+2, -(s-a[i]+1));
            }
            add_p(i+2, 1);
            add_p(min(n+1, i+a[i]+1), -1);
        }
        cout << ans << endl;
    }
    return 0;
}