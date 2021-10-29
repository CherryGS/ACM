#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

const int ed = 400001;
const int st = 0;
int n, mx;
int val[400400];
int in[400400], out[400400];
int tot[2000010];
int las[400400];

bool vis[400400];
vector<int> to[400400];

void dfs(cint loc, cint lim) {
    vis[loc] = 1;
    if(loc == ed) return;
    las[loc] = lim - val[loc];
    for(int v: to[loc]) {
        if(!vis[v]) dfs(v, lim);
        las[loc] = min(las[loc], las[v]);
    }
    // if(lim == 8) cout << loc << "---" << r << endl;
    if(las[loc] >= 0) tot[las[loc]]++;
}

void debug() {
    cout << endl;
    for(int i=1; i<=mx; i++)
        cout << tot[i] << ' ';
    cout << endl;
}

bool check(cint lim) {
    if(lim < mx) return 0;
    memset(tot, 0, sizeof tot);
    memset(vis, 0, sizeof vis);
    dfs(st, lim);
    if(las[st] < 0) return 0;
    for(int i=0; i<=ed-1; i++) {
        tot[i] += tot[i-1];
        if(tot[i] > i+1) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int rr, v;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> val[i] >> rr;
        mx = max(mx, val[i]);
        for(int j=1; j<=rr; j++) {
            cin >> v;
            to[v].push_back(i);
            out[v]++;
            in[i]++;
        }
    }
    las[ed] = 2000000; 
    for(int i=1; i<=n; i++) {
        if(!in[i]) to[st].push_back(i);
        if(!out[i]) to[i].push_back(ed);
    }
    int l = mx, r = 2000000, mid;
    while(l < r) {
        mid = (l+r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    if(check(l-1)) --l;
    if(!check(l)) ++l;
    cout << l-1 << endl;
    return 0;
}