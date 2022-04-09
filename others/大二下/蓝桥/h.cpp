// n^2
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n;
ll l;

struct node {
    int x, y;
    ll w;
    int id;
    int ans;
    void init(int r) { cin >> x >> y >> w; id = r; }
};

bool cmp(const node&a, const node&b) {
    if(b.x >= 0) {
        if(a.x < 0) { return false; }
        else {
            if(1ll * b.x * a.y == 1ll * a.x * b.y) { return a.w < b.w; }
            if(1ll * b.y * a.y < 0) { return 1ll * b.x * a.y < 1ll * a.x * b.y; }
            else { return 1ll * b.x * a.y > 1ll * a.x * b.y; }
        }
    }
    else {
        if(a.x >= 0) { return true; }
        else {
            if(1ll * b.x * a.y == 1ll * a.x * b.y) { return a.w < b.w; }
            if(1ll * b.y * a.y < 0) { return 1ll * b.x * a.y > 1ll * a.x * b.y; }
            else { return 1ll * b.x * a.y < 1ll * a.x * b.y; }
        }
    }
}

bool cmp1(const node&a, const node&b) { return a.id < b.id; }

node a[100100];
int vis[100100];

bool check(int x) {
    return l >= sqrt(1ll*a[x].x*a[x].x + 1ll*a[x].y*a[x].y);
}

bool same(int x, int y) {
    auto &k1 = a[x];
    auto &k2 = a[y];
    if(k1.x >= 0 && k2.x < 0) { return false; }
    else if(k2.x >= 0 && k1.x < 0) { return false; }
    return 1ll * k1.x * k2.y == 1ll * k2.x * k1.y;
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> l;
    for(int i=1; i<=n; i++) { a[i].init(i); }
    sort(a+1, a+1+n, cmp);
    // for(int i=1; i<=n; i++) {
    //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].w << endl;
    // }
    int cnt = 0;
    int lst = 0;
    bool ok = true;
    bool okk = true;
    while(ok == true) {
        ok = false;
        okk = true;
        lst = 0;
        for(int i=1; i<=n; i++) {
            if(!vis[i] && check(i)) {
                if(lst && same(lst, i)) { vis[i] = vis[lst]; ++cnt; }
                else { vis[i] = ++cnt; }
                l += a[i].w;
                lst = i;
                okk = ok = true;
            }
        }
    }
    for(int i=1; i<=n; i++) { a[i].ans = vis[i]; }
    sort(a+1, a+1+n, cmp1);
    for(int i=1; i<=n; i++) {
        if(a[i].ans) { cout << a[i].ans; }
        else { cout << -1; }
        if(i != n) { cout << ' '; }
    }
}