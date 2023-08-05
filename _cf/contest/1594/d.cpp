#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
bool flag;

struct edge {
    int u, v;
    bool st;
    bool operator < (const edge & a) const {
        return u == a.u ? v < a.v : u < a.u;
    }
} r[500500];

int h[200200], nx[500500*2], to[500500*2];
bool w[500500*2];
bool vis[200200];
bool val[200200];
int cnt;
int sum = 0;

void add(cint f, cint t, bool co) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

int dfs(cint loc, bool st) {
    ++sum;
    vis[loc] = 1;
    val[loc] = st;
    int ss = 0;
    for(int i=h[loc]; i; i=nx[i]) {
        if(!vis[to[i]] && !flag) {
            ss += dfs(to[i], w[i] ^ st);
        }
        else {
            if(val[to[i]] != w[i] ^ st) {
                flag = 1;
                return 0;
            }
        }
    }
    return ss + st;
}

int main() {
    cin >> t;
    while(t--) {
        int u, v;
        string s;
        cin >> n >> m;
        cnt = 0;
        flag = 0;
        for(int i=1; i<=n; i++) {
            h[i] = 0;
            vis[i] = 0;
        }
        for(int i=1; i<=m; i++) {
            cin >> u >> v >> s;
            if(u > v) swap(u, v);
            r[i] = {u, v, s[0] == 'i'};
        }
        sort(r+1, r+1+m);
        for(int i=1; i<m; i++) {
            if(r[i].u == r[i+1].u && r[i].v == r[i+1].v) {
                if(r[i].st != r[i+1].st) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) {
            cout << -1 << endl;
            continue;
        }
        for(int i=1; i<=m; i++) {
            if(r[i].u != r[i+1].u || r[i].v != r[i+1].v) {
                add(r[i].u, r[i].v, r[i].st);
                add(r[i].v, r[i].u, r[i].st);
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                sum = 0;
                int r = dfs(i, 1);
                ans += max(r, sum-r);
            }
        }
        if(flag) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
/*
1
18 4
14 17 i
6 12 i
6 9 c
12 13 c

*/