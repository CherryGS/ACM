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
int bcj[1001][2];

int fd(cint x, cint st) {
    return bcj[x][st] == x ? x : bcj[x][st] = fd(bcj[x][st], st);
}

int main() {
    cin >> n >> m1 >> m2;
    int u, v;
    for(int i=1; i<=n; i++) bcj[i][0] = bcj[i][1] = i;
    for(int i=1; i<=m1; i++) {
        cin >> u >> v;
        bcj[fd(u, 0)][0] = fd(v, 0);
    }
    for(int i=1; i<=m2; i++) {
        cin >> u >> v;
        bcj[fd(u, 1)][1] = fd(v, 1);
    }
    vector<pii> e;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int s1 = fd(i, 0), s2 = fd(j, 0);
            if(s1 != s2) {
                int t1 = fd(i, 1), t2 = fd(j, 1);
                if(t1 != t2) {
                    bcj[s1][0] = s2;
                    bcj[t1][1] = t2;
                    e.push_back( {i, j} );
                }
            }
        }
    }
    cout << e.size() << endl;
    for(auto k: e) {
        cout << k.first << ' ' << k.second << endl;
    }
    return 0;
}