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

int t, n;
int h[300300][2], nx[600600][2], to[600600][2], cnt[2];
int le[300300][2], dfn;
pair<int, int> bac[300300];
int re_ans;

set<pair<int,int> > e;

void add(cint f, cint t, bool st) {
    nx[++cnt[st]][st] = h[f][st];
    h[f][st] = cnt[st];
    to[cnt[st]][st] = t;
}

void pre_dfs(cint loc, cint fa) {
    le[loc][0] = ++dfn;
    for(int i=h[loc][1]; i; i=nx[i][1])
        if(to[i][1] != fa) {
            pre_dfs(to[i][1], loc);
        }
    le[loc][1] = dfn;
}

void debug() {
    for(auto k = e.begin(); k != e.end(); ++k) {
        pair<int,int> tmp = *k;
        cout << tmp.first << "-------" << tmp.second << endl;
    }
}

bool check(cint loc) {
    auto k = e.upper_bound(make_pair(le[loc][0], le[loc][1]));
    pair<int, int> tmp(-1, -1);
    if(k != e.begin()) { tmp = *(--k); ++k; }
    // cout << tmp.first << ' ' << tmp.second << endl;
    // cout << loc << ' ' << le[loc][0] << ' ' << le[loc][1] << ' ' << e.size() << endl;
    // debug();
    if(k == e.begin() || tmp.second < le[loc][0]) {
        e.insert(make_pair(le[loc][0], le[loc][1]));
        return 1;
    } else {
        --k;
        bac[loc] = *k;
        e.erase(k);
        e.insert(make_pair(le[loc][0], le[loc][1]));
        return 0;
    }
}

void back(cint loc) {
    e.erase(e.find(make_pair(le[loc][0], le[loc][1])));
    if(bac[loc].first == -1) return;
    e.insert(bac[loc]);
    bac[loc] = make_pair(-1, -1);
}

void dfs(cint loc, cint fa, int ans) {
    // cout << endl;
    int s = check(loc);
    ans += s;
    // cout << loc << "-----" << s << "-----" << ans << endl;
    re_ans = max(ans, re_ans);
    for(int i=h[loc][0]; i; i=nx[i][0])
        if(to[i][0] != fa) {
            dfs(to[i][0], loc, ans);
        }
    back(loc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        e.clear();
        cin >> n;
        int a;
        re_ans = dfn = cnt[0] = cnt[1] = 0;
        for(int i=1; i<=n; i++) {
            h[i][0] = h[i][1] = 0;
        }
        int u, v;
        for(int i=2; i<=n; i++) {
            cin >> u >> v;
            add(u, v, 1);
            add(v, u, 1);
        }
        for(int i=2; i<=n; i++) {
            cin >> u >> v;
            add(u, v, 0);
            add(v, u, 0);
        }
        pre_dfs(1, 1);
        dfs(1, 1, 0);
        cout << re_ans << endl;
    }
    return 0;
}
/*
1
12
1 2 3 3 4 6 5 7 6 7 8
1 2 3 3 5 5 7 4 9 8 5
*/