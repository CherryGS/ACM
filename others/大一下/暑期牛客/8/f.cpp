#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, q;
char mp[505][505];
bitset<500*500+1> r[501];
bool ans[500500];

struct node { int x, y, id; };
vector<node> e[505][505];
int dfs(cint x, cint y, cint dx, cint dy) {
    if(x > n) return x-1;
    if(y > m) return y-1;
    if(mp[x][y] == '1') return (dx == 1 ? x : y)-1;
    return dfs(x+dx, y+dy, dx, dy);
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> mp[i][j];
    cin >> q;
    int a, x1, x2, y1, y2;
    for(int i=1; i<=q; i++) {
        cin >> a >> x1 >> y1 >> x2 >> y2;
        if(a == 1) { if(y1 == y2 && x1 <= x2) ans[i] = (x2 <= dfs(x1, y1, 1, 0)); }
        else if(a == 2) { if(x1 == x2 && y1 <= y2) ans[i] = (y2 <= dfs(x1, y1, 0, 1)); }
        else e[x2][y2].push_back( {x1, y1, i} );
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(mp[i][j] == '0') {
                r[j][(i-1)*m+j] = 1;
                r[j] |= r[j-1];
                if(e[i][j].size()) for(node x:e[i][j]) ans[x.id] = r[j][m*(x.x-1)+x.y];
            }
            else r[j].reset();
        }
    }
    for(int i=1; i<=q; i++)
        if(ans[i]) cout << "yes" << endl;
        else cout << "no" << endl;
    return 0;
}