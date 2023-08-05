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
int a[1001][1001];
int my[1001][1001];
bool vis[1001][1001];

struct node {
    int x, y, c;
    void pr() {
        cout << x << ' ' << y << ' ' << c << '\n';
    }
};

int check(cint i, cint j) {
    int mx = max(max(a[i][j], a[i][j+1]), max(a[i+1][j], a[i+1][j+1]));
    if(a[i][j] == mx || !a[i][j])
        if(a[i][j+1] == mx || !a[i][j+1])
            if(a[i+1][j] == mx || !a[i+1][j])
                if(a[i+1][j+1] == mx || !a[i+1][j+1])
                    { return mx; }
    return -1;
}

void brush(cint i, cint j) {
    a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 0;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    vector<node> ans;
    queue<pii> q;
    for(int i=1; i<n; i++) 
        for(int j=1; j<m; j++) {
            int r = check(i, j);
            if(r != -1 && r != 0) {
                ans.push_back({i, j, r});
                vis[i][j] = true;
                if(a[i][j]) q.push({i, j});
                if(a[i][j+1]) q.push({i, j+1});
                if(a[i+1][j]) q.push({i+1, j});
                if(a[i+1][j+1]) q.push({i+1, j+1});
                brush(i, j);
            } 
        }
    while(!q.empty()) {
        auto k = q.front();
        int i = k.first, j = k.second;
        q.pop();
        for(int di = i-1; di <= i+1; ++di) {
            for(int dj = j-1; dj <= j+1; ++dj) {
                if(di >= 1 && di < n && dj >= 1 && dj < m && !vis[di][dj]) {
                    int r = check(di, dj);
                    if(r != -1 && r != 0) {
                        ans.push_back({di, dj, r});
                        vis[di][dj] = true;
                        if(a[di][dj]) q.push({di, dj});
                        if(dj < m && a[di][dj+1]) q.push({di, dj+1});
                        if(di < n && a[di+1][dj]) q.push({di+1, dj});
                        if(di < n && dj < m && a[di+1][dj+1]) q.push({di+1, dj+1});
                        brush(di, dj);
                    }
                }
            }
        }
    }
    bool flag = true;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=m; j++)
            if(a[i][j]) { flag = false; break; }
    if(flag) {
        cout << ans.size() << '\n';
        for(auto k = ans.rbegin(); k != ans.rend(); ++k) k->pr();
    } else { cout << -1 << '\n'; }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}