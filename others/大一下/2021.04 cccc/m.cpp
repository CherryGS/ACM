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
#define pii pair<int, ll>
#define ls lson[loc]
#define rs rson[loc]

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int node_num = 100100;

int n, m, q;
ll a[100100];
int h[100100], nx[200200], to[200200], cnt;
int h1[100100], nx1[200200], to1[200200], cnt1;
ll dis_1[node_num], w[200200];
ll dis_2[node_num], w1[200200];
priority_queue<pii, vector<pii>, greater<pii> > e;

void add(cint f, cint t, ll co1) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co1;
}

void add1(cint f, cint t, ll co2) {
    nx1[++cnt1] = h1[f];
    h1[f] = cnt1;
    to1[cnt1] = t;
    w1[cnt1] = co2;
}

void dij_1(cint start) {
    for(int i=1; i<=n; i++) dis_1[i] = inf_ll;
    dis_1[start] = 0;
    e.push(make_pair(0, start));
    while(!e.empty()) {
        ll now_dis = e.top().first;
        int now_loc = e.top().second;
        e.pop();
        for(int i=h[now_loc]; i; i=nx[i]) {
            if(dis_1[to[i]] > now_dis + w[i]) {
                dis_1[to[i]] = now_dis + w[i];
                e.push(make_pair(dis_1[to[i]], to[i]));
            }
        }
    }
}

void dij_2(cint start) {
    while(!e.empty()) { e.pop(); }
    for(int i=1; i<=n; i++) dis_2[i] = inf_ll;
    dis_2[start] = 0;
    e.push(make_pair(0, start));
    while(!e.empty()) {
        ll now_dis = e.top().first;
        int now_loc = e.top().second;
        e.pop();
        for(int i=h1[now_loc]; i; i=nx1[i]) {
            if(dis_2[to1[i]] > now_dis + w1[i]) {
                dis_2[to1[i]] = now_dis + w1[i];
                e.push(make_pair(dis_2[to1[i]], to1[i]));
            }
        }
    }
}

int lson[400100], rson[400100], son = 1;
ll mx[400400];
void build(cint l, cint r, int & loc) {
    if(!loc) loc = ++son;
    if(l == r) {
        if(dis_2[l] < inf_ll && dis_1[l] < inf_ll)
            mx[loc] = (dis_2[l]+a[l]-1)/a[l]+dis_1[l];
        else mx[loc] = inf_ll;
        return;
    }
    int mid = (l+r) >> 1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    mx[loc] = min(mx[ls], mx[rs]);
}

void insert(cint l, cint r, cint pt, int&loc) {
    if(l == r) {
        if(dis_2[l] < inf_ll && dis_1[l] < inf_ll)
            mx[loc] = (dis_2[l]+a[l]-1)/a[l]+dis_1[l];
        else mx[loc] = inf_ll;
        return;
    }
    int mid = (l+r) >> 1;
    if(pt <= mid) insert(l, mid, pt, ls);
    else insert(mid+1, r, pt, rs);
    mx[loc] = min(mx[ls], mx[rs]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    int u, v, c, d;
    for(int i=1; i<=m; i++) {
        cin >> u >> v >> c >> d;
        add(u, v, c);
        add1(v, u, d);
    }
    dij_1(1);
    dij_2(n);

    int root = 1;
    for(int i=1; i<=n; i++) cin >> a[i];
    // for(int i=1; i<=n; i++) {
    //     cout << dis_1[i] << "---" << dis_2[i] << "---" << (dis_2[i]+a[i]-1)/a[i]+dis_1[i] << endl;
    // }
    build(1, n, root);

    for(int i=1; i<=q; i++) {
        cin >> c >> d;
        a[c] = d;
        insert(1, n, c, root);
        cout << mx[root] << endl;
    }

    return 0;
}