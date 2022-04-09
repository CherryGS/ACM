// nlogn
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

struct node {
    int l, r, id;
    bool ok;
    void init(int x) {
        ok = false;
        id = x;
        cin >> l >> r;
    }
};

int n, m, x;
int a[200100];
int len[200100];
node q[200200];
map<int, int> e;

bool cmp1(const node&a, const node&b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
}

bool cmp2(const node&a, const node&b) {
    return a.id < b.id;
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    e[a[1] ^ x] = 1;
    for(int i=2; i<=n; i++) {
        if(e.find(a[i]) != e.end()) { len[i] = e[a[i]]; }
        e[a[i] ^ x] = i;
    }
    for(int i=1; i<=m; i++) { q[i].init(i); }
    sort(q+1, q+1+m, cmp1);
    int dl = 0, dr = 0;
    int loc = 1;
    for(int i=1; i<=m; i++) {
        while(loc <= n && loc <= q[i].r) {
            dl = max(dl, len[loc]);
            ++loc;
        }
        // cout << i << ' ' << q[i].id << ' ' << q[i].l << ' ' << q[i].r << ' ' << dl << ' ' << loc << endl;
        if(q[i].l <= dl) { q[i].ok = true; }
    }
    sort(q+1, q+1+m, cmp2);
    for(int i=1; i<=m; i++) {
        if(q[i].ok == true) { cout << "yes" << '\n'; }
        else { cout << "no" << '\n'; }
    }
}