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

int n, t, k;

int query(cint l, cint r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void print(cint ans) {
    cout << "! " << ans << endl;
}

void dfs(cint l, cint r, cint num) {
    if(l == r) {
        print(l);
        return;
    }
    int mid = (l+r) >> 1;
    int s = (mid-l+1) - query(l, mid);
    // cout << s << endl;
    if(s >= num) dfs(l, mid, num);
    else dfs(mid+1, r, num-s);
}

int main() {
    cin >> n >> t >> k;
    dfs(1, n, k);
    return 0;
}