#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

typedef pair<int,int> pii;
int n, m1, m2;
int bcj[100001][2];

int fd(cint x, cint st) {
    return bcj[x][st] == x ? x : bcj[x][st] = fd(bcj[x][st], st);
}

int main() {
    cin >> n >> m1 >> m2;
    int u, v;
    for(int i=1; i<=n; i++) bcj[i][0] = bcj[i][1] = i;
    for(int i=1; i<=m1; i++) {
        cin >> u >> v;
        u = fd(u, 0), v = fd(v, 0);
        if(u < v) swap(u, v);
        bcj[u][0] = v;
    }
    for(int i=1; i<=m2; i++) {
        cin >> u >> v;
        u = fd(u, 1), v = fd(v, 1);
        if(u < v) swap(u, v);
        bcj[u][1] = v;
    }
    vector<pii> e;
    for(int i=2; i<=n; i++) {
        int s1 = fd(i, 0), s2 = fd(i, 1);
        if(s1 != 1 && s2 != 1) {
            bcj[s1][0] = 1;
            bcj[s2][1] = 1;
            e.push_back( {1, i} );
        }
    }
    queue<int> r[2];
    for(int i=2; i<=n; i++) {
        int s1 = fd(i, 0), s2 = fd(i, 1);
        if(s1 == 1 && s2 != 1) r[0].push(i);
        if(s1 != 1 && s2 == 1) r[1].push(i);
    }
    while(!r[0].empty() && !r[1].empty()) {
        while(!r[0].empty() && fd(r[0].front(), 0) == 1 && fd(r[0].front(), 1) == 1) r[0].pop();
        while(!r[1].empty() && fd(r[1].front(), 0) == 1 && fd(r[1].front(), 1) == 1) r[1].pop();
        if(!r[0].empty() && !r[1].empty()) {
            int s1 = r[0].front(), s2 = r[1].front();
            r[0].pop(), r[1].pop();
            bcj[fd(s2, 0)][0] = 1;
            bcj[fd(s1, 1)][1] = 1;
            e.push_back( {s1, s2} );
        }
    }

    cout << e.size() << endl;
    for(auto k: e) {
        cout << k.first << ' ' << k.second << endl;
    }
    return 0;
}