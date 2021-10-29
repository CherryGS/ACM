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
int a[200200];
int ans[200200][2];
bool st[200200];

int b[500100];
int lowbit(cint x) { return x&-x; }

void add_p(cint num, int loc) {
    while(loc <= n) {
        b[loc] += num;
        loc = loc + lowbit(loc);
    }
}

int get_r(int x) {
    // 1~x
    int ans = 0;
    while(x) {
        ans += b[x];
        x -= lowbit(x);
    }
    return ans;
}

int get_p(int x) {
    return get_r(x) - get_r(x-1);
}

bool check(cint x, cint y) {
    return get_r(y) - get_r(x-1) > 0;
}

int dfs(cint l, cint r) {
    if(l == r) return l;
    int mid = (l+r) >> 1;
    if(check(mid+1, r)) return dfs(mid+1, r);
    else return dfs(l, mid);
}

int sol(int r) {
    int mid = dfs(1, r);
    add_p(-1, mid);
    return mid;
}


int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {cin >> a[i];}
        for(int i=1; i<=n; i++) b[i] = 0;
        for(int i=1; i<=n; i++) ans[i][0] = ans[i][1] = st[i] = 0, add_p(1, i);
        for(int i=1; i<=n; i++) if(a[i] != a[i-1]) ans[i][0] = ans[i][1] = a[i], st[a[i]] = 1, add_p(-1, a[i]);
        int l = 1;
        for(int i=1; i<=n; i++) if(!st[i]) {
            while(ans[l][0]) ++l;
            ans[l][0] = i;
        }
        int la;
        for(int i=1; i<=n; i++) {
            if(ans[i][1]) la = ans[i][1];
            else {
                ans[i][1] = sol(la-1);
            }
        }
        for(int i=1; i<=n; i++) cout << ans[i][0] << ' ';
        cout << endl;
        for(int i=1; i<=n; i++) cout << ans[i][1] << ' ';
        cout << endl;
    }
    return 0;
}