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
ll l, r;
int ans[101];

bool sol(int x) {
    if(x < 10) return !(x%3);
    else {
        if(!((x%10)%3)) return 1;
        if(!((x/10)%3)) return 1;
        if(!((x%10+x/10)%3)) return 1;
    }
    return 0;
}

void init() {
    ans[0] = 1;
    for(int i=1; i<=99; i++) {
        ans[i] = ans[i-1] + sol(i);
    }
}

int main() {
    init();
    cin >> t;
    while(t--) {
        ll ans1 = 0;
        cin >> l >> r;
        if(r <= 99) ans1 = ans[r]-ans[l-1];
        else {
            if(l <= 99) ans1 = r - 99 + ans[99] - ans[l-1];
            else ans1 = r - l + 1;
        }
        cout << ans1 << endl;
    }
    return 0;
}