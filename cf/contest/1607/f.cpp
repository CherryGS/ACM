#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n, m;
char s[2002][2002];
int to[2002*2002];
int deg[2002*2002];
int mx[2002*2002];
int ans;

int v(cint x, cint y) { return (x-1)*m+y; }

void dfs(cint x) {
    cout << x << endl;
    if(mx[x] || !to[x]) {
        if(!mx[x]) mx[x] = 1;
        return;
    }
    dfs(to[x]);
    mx[x] += mx[to[x]] + 1;
    ans = max(ans, mx[x]);
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                cin >> s[i][j]; 
                deg[v(i, j)] = 0;
                mx[v(i, j)] = 0;
                to[v(i, j)] = 0;
            }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i][j] == 'L') {
                    if(j != 1) to[v(i,j)] = v(i,j-1);
                }
                else if(s[i][j] == 'R') {
                    if(j != m) to[v(i,j)] = v(i, j+1);
                }
                else if(s[i][j] == 'U') {
                    if(i != 1) to[v(i, j)] = v(i-1, j);
                }
                else if(s[i][j] == 'D') {
                    if(i != n) to[v(i,j)] = v(i+1, j);
                }
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                deg[to[v(i, j)]]++;
            }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(!deg[v(i, j)]) dfs(v(i,j));
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(!mx[v(i, j)]) { mx[v(i,j)] = 1; dfs(v(i,j));}
            }
        }
        cout << ans << endl;
    }
    return 0;
}