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

int n, m;
char mp[201][201];
bool vis[201][201];

bool check(cint x, cint y) {
    if(x > n || x < 1) return false;
    if(y > m || y < 1) return false;
    return !vis[x][y] && mp[x][y-1] == '1';
}

bool valid(cint tl, cint tr, cint tu, cint td) {
    for(int i=tu; i<=td; i++) {
        for(int j=tl; j<=tr; j++) {
            if(mp[i][j-1] == '0') return false;
        }
    }
    return true;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> mp[i];
    }
    memset(vis, 0, sizeof vis);
    bool ok = true;
    for(int i=1; i<=n && ok; i++) {
        for(int j=1; j<=m && ok; j++) {
            if(vis[i][j] || mp[i][j-1] == '0') continue;
            queue<pii> q;
            q.push({i, j});
            vis[i][j] = 1;
            int tl = j, tr = j , tu = i, td = i;
            while(!q.empty()) {
                auto k = q.front();
                q.pop();
                if(check(k.first+1, k.second)) {
                    q.push({k.first+1, k.second});
                    vis[k.first+1][k.second] = 1;
                    td = max(td, k.first+1);
                }
                if(check(k.first, k.second+1)) {
                    q.push({k.first, k.second+1});
                    vis[k.first][k.second+1] = 1;
                    tr = max(tr, k.second+1);
                }
                if(check(k.first-1, k.second)) {
                    q.push({k.first-1, k.second});
                    vis[k.first-1][k.second] = 1;
                    tu = min(tu, k.first-1);
                }
                if(check(k.first, k.second-1)) {
                    q.push({k.first, k.second-1});
                    vis[k.first][k.second-1] = 1;
                    tl = min(tl, k.second-1);
                }
            }
            // cout << tl << ' ' << tr << ' ' << tu << ' ' << td << endl;
            if(!valid(tl, tr, tu, td)) { ok = false; break; }
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}