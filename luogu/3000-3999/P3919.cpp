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

const int mx_node = 1000000;
const int mx_v = 1000000;
int lson[mx_node<<5], rson[mx_node<<5], cnt;
int node[mx_node<<5];
int root[mx_v], ct;
int to[mx_v];

int n, m;
int a[1001000];

void build(cint l, cint r, int&loc) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        node[loc] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, lson[loc]);
    build(mid+1, r, rson[loc]);
}

void add(cint l, cint r, cint des, cint val, cint old, int& loc) {
    if(!loc) loc = ++cnt;
    if(l == r) {
        node[loc] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(des <= mid) {
        rson[loc] = rson[old];
        add(l, mid, des, val, lson[old], lson[loc]);
    } else {
        lson[loc] = lson[old];
        add(mid+1, r, des, val, rson[old], rson[loc]);
    }
}

int query(cint l, cint r, cint des, cint loc) {
    if(l == r) {
        return node[loc];
    }
    int mid = (l+r) >> 1;
    if(des <= mid) return query(l, mid, des, lson[loc]);
    else return query(mid+1, r, des, rson[loc]);
}

int main() {
    scanf("%d%d", &n, &m);
    int s[4];
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    build(1, n, root[0]);
    for(int i=1; i<=m; i++) {
        scanf("%d%d%d", &s[0], &s[1], &s[2]);
        if(s[1] == 1) {
            to[i] = ++ct;
            scanf("%d", &s[3]);
            add(1, n, s[2], s[3], root[to[s[0]]], root[to[i]]);
        } else {
            to[i] = to[s[0]];
            int ans = query(1, n, s[2], root[to[s[0]]]);
            printf("%d\n", ans);
        }
    }
    return 0;
}