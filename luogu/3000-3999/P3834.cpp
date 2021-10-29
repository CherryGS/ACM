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

const int mx_node = 200000;

int lson[mx_node<<5], rson[mx_node<<5], cnt;
int node[mx_node<<5];
int root[mx_node];

int n, m;
int a[200200], b[200200];
map<int, int> e;
int to[200200];

void ins(cint l, cint r, cint des, cint old, int&loc) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        node[loc] = node[old] + 1;
        return;
    }
    int mid = (l+r) >> 1;
    if(des <= mid) {
        rson[loc] = rson[old];
        ins(l, mid, des, lson[old], lson[loc]);
    } else {
        lson[loc] = lson[old];
        ins(mid+1, r, des, rson[old], rson[loc]);
    }
    node[loc] = node[lson[loc]] + node[rson[loc]];
}

int query(cint l, cint r, int k, cint old, cint loc) {
    if(l == r) return to[l];
    int mid = (l+r) >> 1;
    int dt = node[lson[loc]] - node[lson[old]];
    // cout << to[l] << "---" << to[r] << ' ' << dt << ' ' << to[mid] << endl;
    if(dt >= k) {
        return query(l, mid, k, lson[old], lson[loc]);
    } else {
        return query(mid+1, r, k-dt, rson[old], rson[loc]);
    }
}

void build(cint l, cint r, int&loc) {
    if(!loc) loc = ++cnt;
    if(l == r) return;
    int mid = (l+r) >> 1;
    build(l, mid, lson[loc]);
    build(mid+1, r, rson[loc]);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]), b[i] = a[i];
    sort(a+1, a+1+n);
    int num = 0;
    a[0] = 1e9+1;
    for(int i=1; i<=n; i++) {
        if(a[i] != a[i-1]) {
            e[a[i]] = ++num;
            to[num] = a[i];
        }
    }
    build(1, num, root[0]);
    for(int i=1; i<=n; i++) ins(1, num, e[b[i]], root[i-1], root[i]);
    int q1, q2, kk;
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d", &q1, &q2, &kk);
        int ans = query(1, num, kk, root[q1-1], root[q2]);
        printf("%d\n", ans);
    }
    return 0;
}
/*
8 1
8 45 34 33 54 100 22 22 
8 8 1
*/