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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int h[10001][10001];
bool vis[10001][10001];

bool solve(cint T) {
    cin >> n >> m;
    queue<pii> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> h[i][j];
            if(h[i][j] == 0) { q.push({i, j}); }
        }
    }
    int x, y;
    while(!q.empty()) {
        auto u = q.front();
        x = u.first, y = u.second;
        q.pop();
        if(x > 1 && h[x][y] <= h[x-1][y]) { }
    }
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}