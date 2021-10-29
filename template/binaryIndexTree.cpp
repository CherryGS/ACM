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
ll a[500100];
int lowbit(cint x) { return x&-x; }

void add_p(cint num, int loc) {
    while(loc <= n) {
        a[loc] += num;
        loc = loc + lowbit(loc);
    }
}

ll get_r(int x) {
    // 1~x
    ll ans = 0;
    while(x) {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    int a;
    for(int i=1; i<=n; i++) {
        cin >> a;
        add_p(a,i);
        add_p(-a,i+1);
    }
    int b,c;
    for(int i=1; i<=m; i++) {
        cin >> a;
        if(a==1) {
            cin >> a >> b >> c;
            add_p(c, a);
            add_p(-c, b+1);
        } else {
            cin >> a;
            cout << get_r(a) << endl;
        }
    }
    
    return 0;
}