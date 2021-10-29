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
#define ls lson[loc]
#define rs rson[loc]

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int mx_node = 200000;
int n, t, k;
int root, cnt;
int node[mx_node << 4];
int lson[mx_node << 4], rson[mx_node << 4];
bool vis[mx_node << 4];

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

void update(cint l, cint r, cint des, cint loc) {
    if(vis[loc]) ++node[loc];
    if(l == r) return;
    int mid = (l+r) >> 1;
    if(des <= mid) update(l, mid, des, ls);
    else update(mid+1, r, des, rs);
}

void sol(cint l, cint r, int &loc, cint num) {
    if(l == r) {
        print(l);
        update(1, n, l, root);
        return;
    }
    int mid = (l+r) >> 1;
    if(!ls) ls = ++cnt;
    if(!rs) rs = ++cnt;
    if(!vis[ls]) node[ls] = query(l, mid), vis[ls] = 1;
    int s = mid-l+1 - node[ls];
    if(s >= num) sol(l, mid, ls, num);
    else sol(mid+1, r, rs, num-s);
}

int main() {
    cin >> n >> t;
    while(t--) {
        cin >> k;
        sol(1, n, root, k);
    }
    return 0;
}