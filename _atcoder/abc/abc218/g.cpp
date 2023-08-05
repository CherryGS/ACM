#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int a[100100];
vector<int> to[100100];
bool odd[100100];

void dfs1(cint loc, cint fa) {
    odd[loc] = odd[fa] ^ 1;
    for(int v: to[loc]) if(v != fa) dfs1(v, loc);
}

int n1, n2;

bool dfs2(cint loc, cint fa, cint lim, cint mn, cint mx) {
    bool st = 0;
    for(int v: to[loc]) {
        if(v != fa) {
            if(a[v] >= lim) {
                ++n1;
                mn = min(mn, a[v]);
            }
            else {
                ++n2;
                mx = max(mx, a[v]);
            }
            if(odd[loc]) st |= dfs2(v, loc, lim);
            else st &= dfs2(v, loc, lim);
        }
    }
    if(to[loc].size() == 1 && loc != 1) {

    }
}

bool check(cint x) {
    mn = inf_int;
    mx = -1;
    n1 = n2 = 0;
    dfs2(1, 1, x, inf_int, -1);
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[v].push_back(u);
        to[u].push_back(v);
    }
    dfs1(1, 1);
    int l = 0, r = 1e9+1, mid;
    while(l < r) {
        mid = (l+r) >> 1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    if(!check(l)) -- l;
    if(check(l+1)) ++ l;
    cout << l << endl;
    return 0;
}