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

int n;
int a[100100];
vector<int> to[100100];
int son[100100];
int bson[100100];
int val[1050100][18][2];
int q[100100], cnt;
ll ans = 0;

void fd_son(cint loc, cint fa) {
    son[loc] = 1;
    for(int v: to[loc]) {
        if(v != fa) {
            fd_son(v, loc);
            son[loc] += son[v];
            if(son[v] > son[bson[loc]]) bson[loc] = v;
        }
    }
}

void cacu(cint r, cint x) {
    // cout << x << " - - - - " << r << endl;
    for(int i=0; i<18; i++)
        ans += val[r][i][!(1&(x>>i))] * (1<<i);
}

void check(cint loc, cint fa, cint co) {
    cacu(a[loc]^co, loc);
    for(int v: to[loc]) {
        if(v != fa) check(v, loc, co);
    }
}

void ins(cint r, cint x) {
    for(int i=0; i<18; i++)
        ++val[r][i][1&(x>>i)];
    q[++cnt] = r;
}

void update(cint loc, cint fa) {
    ins(a[loc], loc);
    for(int v: to[loc]) {
        if(v != fa) update(v, loc);
    }
}

void clear() {
    while(cnt) {
        memset(val[q[cnt]], 0, sizeof val[q[cnt]]);
        --cnt;
    }
}

void sol(cint loc, cint fa) {
    // cout << loc << " ---- " << fa << endl;
    for(int v: to[loc]) {
        if(v != fa && v != bson[loc]) {
            sol(v, loc);
            clear();
        }
    }
    if(bson[loc]) {
        sol(bson[loc], loc);
    }
    for(int v: to[loc]) {
        if(v != fa && v != bson[loc]) {
            // cout << loc << " ------- " << cnt << endl;
            check(v, loc, a[loc]);
            update(v, loc);
        }
    }
    ins(a[loc], loc);
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    fd_son(1, 1);
    sol(1, 1);
    cout << ans << endl;
    return 0;
}