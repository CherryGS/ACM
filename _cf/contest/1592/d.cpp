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
vector<int> to[1010];
struct edge {
    int u, v;
} e[1010];
int cnt;

ll query(set<int> q) {
    cout << "? " << q.size() << ' ';
    for(int i: q)
        cout << i << ' ';
    cout << endl;
    cout.flush();
    ll tmp;
    cin >> tmp;
    return tmp;
}

ll check(cint l, cint r) {
    set<int> s;
    for(int i=l; i<=r; i++)
        s.insert(e[i].u), s.insert(e[i].v);
    return query(s);
}

void dfs(cint loc, cint fa) {
    for(int v: to[loc]) {
        if(v != fa) {
            e[++cnt] = {loc, v};
            dfs(v, loc);
        }
    }
}

int main() {
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 1);
    ll st = check(1, n-1);
    int l = 1, r = n-1, mid;
    while(l < r) {
        mid = l + (r - l) / 2;
        if(check(l, mid) != st) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << e[l].u << ' ' << e[l].v << endl;
    return 0;
}