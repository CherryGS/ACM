#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n, k;
int a[100100];
int root[100100];
int cnt;
int node[100100<<4];
int lson[100100<<4], rson[100100<<4];

void update(int l, int r, int ds, int &loc, int ot, int val) {
    if(!loc) { loc = ++cnt; }
    if(l == r) {
        node[loc] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(ds <= mid) { update(l, mid, ds, lson[loc], lson[ot], val); rson[loc] = rson[ot]; }
    else { update(mid+1, r, ds, rson[loc], rson[ot], val); lson[loc] = lson[ot]; }
    node[loc] = max(node[lson[loc]] , node[rson[loc]]);
}

int query(int l, int r, int dl, int dr, int loc) {
    if(!loc) { return 0; }
    if(l >= dl && r <= dr) { return node[loc]; }
    int mid = (l+r) >> 1;
    int ans = 0;
    if(dl <= mid) { ans = max(ans, query(l, mid, dl, dr, lson[loc])); }
    if(dr >= mid+1) { ans = max(ans, query(mid+1, r, dl, dr, rson[loc])); }
    return ans;
}

int dp[100100<<4];
int ls[100100<<4], rs[100100<<4];
int cnt1 = 1;
int rss;

void update1(int l, int r, int ds, int&loc, int val) {
    if(!loc) { loc = ++cnt1; }
    if(l == r) {
        dp[loc] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if(ds <= mid) { update1(l, mid, ds, ls[loc], val); }
    else { update1(mid+1, r, ds, rs[loc], val); }
    dp[loc] = max(dp[ls[loc]], dp[rs[loc]]);
}

int query1(int l, int r, int dl, int dr, int loc) {
    if(!loc) { return 0; }
    // if(rss == 1 && loc == 1) { cout << l << ' ' << r << ' ' << dl << ' ' << dr << ' ' << loc << endl;}
    if(l >= dl && r <= dr) { 
        // if(rss == 1) { cout << l << ' ' << r << ' ' << dl << ' ' << dr << endl; }
        return dp[loc];  
    }
    int mid = (l+r) >> 1;
    int ans = 0;
    if(dl <= mid) { ans = max(ans, query1(l, mid, dl, dr, ls[loc])); }
    if(dr >= mid+1) { ans = max(ans, query1(mid+1, r, dl, dr, rs[loc])); }
    return ans;
}

int main() {
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) {
        int r = query(1, 1e6, 1, a[i]-1, root[i-1]) + 1;
        update(1, 1e6, a[i], root[i], root[i-1], r);
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=10; j++) {
    //         cout << query(1, 1e6, j, j, root[i]) << ' ';
    //     }
    //     cout << endl;
    // }
    // // return 0;
    // cout << endl;
    int rt = 1;
    int ans = 0;
    ans = max(ans, query(1, 1e6, 1, 1e6, root[n-k]));
    for(int i=n; i>k; i--) {
        int r = query1(1, 1e6, a[i], 1e6, rt) + 1;
        // cout << r << ' ' << i << ' ' << a[i] << endl;
        // rss = 0;
        // if(i == n || i == n-1) {
        //     rss = 1;
        //     for(int j=1; j<=10; j++) {
        //         cout << query1(1, 1e6, j, j, rt) << ' ';
        //     }
        //     cout << endl;
        // } else {rss = 0;}
        update1(1, 1e6, a[i], rt, r);
        // cout << r << ' ' << query(1, 1e6, 1, a[i], root[i-k-1]) << ' ' << a[i] << ' ' << i << endl;
        ans = max(ans, r + query(1, 1e6, 1, a[i], root[i-k-1]));
    }
    cout << ans + k;
}