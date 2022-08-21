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

int n, m, s, t;
int mp[101][101];
int val[101];
bool vis[101];

void solve(cint T) {
    memset(vis, 0, sizeof vis);
    memset(mp, 0, sizeof mp);
    memset(val, 0, sizeof val);
    cin >> n >> m >> s >> t;
    int u, v;
    for(int i=1; i<=m; i++) {
        cin >> u >> v;
        mp[u][v] += 1;
        mp[v][u] += 1;
    }
    queue<int> q;
    q.push(t);
    vis[t] = 1;
    while(!q.empty()) {
        auto k = q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                val[i] += mp[i][k];
                if(val[i] >= 2) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    if(val[s] >= 2) { cout << "Join Player\n"; }
    else { cout << "Cut Player\n"; }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}