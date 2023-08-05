#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
int bcj[300300];
vector<int> to[300300];
vector<bool> val[300300];

int fd(cint x) {
    return bcj[x] == x ? x : bcj[x] = fd(bcj[x]);
}

int main() {
    int u, v, x;
    cin >> n >> q;
    for(int i=1; i<=n; i++) bcj[i] = i;
    for(int i=1; i<=q; i++) {
        cin >> u >> v >> x;
        int s1 = fd(u), s2 = fd(v);
        bool flag = 0;
        if(s1 == s2) {
            
        }
        to[u].push_back(v);
        to[v].push_back(u);
        val[u].push_back(x);
        val[v].push_back(x);
    }

    return 0;
}