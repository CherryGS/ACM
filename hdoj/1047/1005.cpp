#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, k;
int h[5005][21], nx[5005][401], to[5005][401], cnt[5005];
int hr[5005][21], nxr[5005][401], tor[5005][401], cntr[5005];
int ans;
int deg[21];
int q[2][5005], ct;
ll val[2][20][5005];
int dq[30], dc;

void add(cint x, cint f, cint t) {
    nx[x][++cnt[x]] = h[x][f];
    h[x][f] = cnt[x];
    to[x][cnt[x]] = t;
}

void addr(cint x, cint f, cint t) {
    nxr[x][++cntr[x]] = hr[x][f];
    hr[x][f] = cntr[x];
    tor[x][cntr[x]] = t;
}

void iter(int x) {
    for(int i=1; i<=m; i++) {
        for(int j=h[x][i]; j; j=nx[x][i]) {
            deg[to[x][i]]++;
        }
    }
}

void iterr(int x) {
    for(int i=1; i<=m; i++) {
        for(int j=hr[x][i]; j; j=nxr[x][i]) {
            deg[tor[x][i]]++;
        }
    }
    dc = 0;
    for(int i=1; i<=m; i++) { if(deg[i] == 0) { dq[++dc] = i; } }
    while(dc) {
        int u = dq[dc];
        --dc;
        for(int i=hr[x][u]; i; i=nxr[x][u]) {
            int v = tor[x][u];
            val[0][v];
        }
    }
}

int init_l(int l, int mid) {
    iterr(mid);
    for(int i=mid-1; i>=l; i--) {

    }
    return l;
}

int init_r(int r, int mid) {
    for(int i=mid-1; i<=r; i++) {

    }
    return r;
}

bool ck(int x) {

}

void cdq(int nl, int nr) {
    int m = (nl+nr) >> 1;
    cdq(nl, m);
    cdq(m+1, nr);
    int lim_r = lower_bound(q[0]+1, q[0]+1+ct, m) - q[0];
    lim_r = (lim_r == ct+1 ? n : q[0][ct]-1);
    int lim_l = lower_bound(q[1]+1, q[1]+1+ct, -m) - q[1];
    lim_l = (lim_l == ct+1 ? 1 : -q[1][ct]+1);
    if(lim_l > m || lim_r < m) { return; }
    int dl = max(lim_l, nl);
    int dr = min(lim_r, nr);
    int l, r, mid;
    for(int i=m+1; i<=dr; i++) {
        l = nl, r = m;
        while(l < r) {
            mid = (l + r) >> 1;
            if(ck(mid)) { r = mid; }
            else { l = mid + 1; }
        }
        if(ck(r)) { ans = max(ans, i-r+1); }
    }
}

bool check(int x) {
    queue<int> q;
    for(int i=1; i<=m; i++) { if(deg[i] == 0) { q.push(i); } }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=h[x][u]; i; i=nx[x][i]) {
            int v = to[x][i];
            deg[v]--;
            if(deg[v] == 0) { q.push(v); }
        }
    }
    bool flag = false;
    for(int i=1; i<=m; i++) { if(deg[i]) { flag = true; } }
    return flag;
}

void solve(cint T) {
    ct = 0;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        int l;
        cin >> l;
        memset(deg, 0, sizeof deg);
        for(int j=1; j<=l; j++) {
            int u, v;
            cin >> u >> v;
            add(i, u, v);
            add(i, v, u);
            deg[v]++;
        }
        if(check(i)) { q[0][++ct] = i; q[1][ct] = -i; }
    }
    sort(q[1]+1, q[1]+1+ct);
    cdq(1, n);
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}