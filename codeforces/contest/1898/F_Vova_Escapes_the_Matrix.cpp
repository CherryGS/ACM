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
#define ifor(s, e) for(int i=s;i<=e;i+=1)
#define jfor(s, e) for(int j=s;j<=e;j+=1)

const int mod = 998244353;
const int hf_int = 0x3f3f3f3f;
const int inf_int = 1e9;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, m;
char s[1001][1001];
int dis[1001][1001];
int dis1[1001][1001][2];
int vis[1001][1001];
int mv[][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct nod {
    int id, x, y;
};


bool checked(int x, int y) {
    return (x >= 0) && (x <= n-1) && (y >= 0) && (y <= m-1) && (s[x][y] == '.');
}

int v(int x, int y) { return x * m + y; }

void solve(cint T) {
    cin >> n >> m;
    ifor(0, n-1) { jfor(0, m-1) {
        dis1[i][j][0] = dis1[i][j][1] = dis[i][j] = inf_int;
        vis[i][j] = 0;
    } }
    ifor(0, n-1) { cin >> s[i]; }
    int pre = 0;
    queue<pii> q;
    ifor(0, n-1) {
        jfor(0, m-1) {
            if(s[i][j] == 'V') { dis[i][j] = 0; q.push({i, j}); s[i][j] = '.'; }
            else if(s[i][j] == '.') { ++pre; }
        }
    }
    while(!q.empty()) {
        auto k = q.front(); q.pop();
        int x = k.first, y = k.second;
        int xx, yy;
        ifor(0, 3) {
            xx = x+mv[i][0]; yy = y+mv[i][1];
            if(checked(xx, yy)) {
                if(dis[xx][yy] == inf_int) {
                // cout << xx << ' ' << yy << endl;
                    dis[xx][yy] = dis[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    // ifor(0, n-1) {
    //     jfor(0, m-1) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int sum = 0, mn = inf_int;
    ifor(0, n-1) {
        if(dis[i][0] < inf_int) { ++sum; mn = min(mn, dis[i][0]); }
        if(dis[i][m-1] < inf_int) { ++sum; mn = min(mn, dis[i][m-1]); }
    }
    ifor(0, m-1) {
        if(dis[0][i] < inf_int) { ++sum; mn = min(mn, dis[0][i]); }
        if(dis[n-1][i] < inf_int) { ++sum; mn = min(mn, dis[n-1][i]); }
    }
    if(sum == 0) { cout << pre << '\n'; return; }
    if(sum == 1) { cout << pre - mn << '\n'; return; }
    queue<nod> q1;
    ifor(0, n-1) {
        if(s[i][0] == '.') { q1.push({v(i,0), i, 0}); dis1[i][0][0] = 0; vis[i][0] = v(i,0); }
        if(s[i][m-1] == '.') { q1.push({v(i,m-1), i, m-1}); dis1[i][m-1][0] = 0; vis[i][m-1] = v(i,m-1); }
    }
    ifor(0, m-1) {
        if(s[0][i] == '.') { q1.push({v(0,i), 0, i}); dis1[0][i][0] = 0; vis[0][i] = v(0,i); }
        if(s[n-1][i] == '.') { q1.push({v(n-1,i), n-1, i}); dis1[n-1][i][0] = 0; vis[n-1][i] = v(n-1,i); }
    }
    // cout << q1.size() << endl;
    while(!q1.empty()) {
        auto k = q1.front(); q1.pop();
        int x = k.x, y = k.y;
        int xx, yy;
        // cout << x << ' ' << y << endl;
        bool r = 0;
        ifor(0, 3) {
            xx = x+mv[i][0]; yy = y+mv[i][1];
            if(checked(xx, yy)) {
                if(vis[xx][yy] == 0) {
                    vis[xx][yy] = k.id;
                    dis1[xx][yy][0] = dis1[x][y][0] + 1;
                    q1.push({k.id, xx, yy});
                }
                else if(vis[xx][yy] != k.id && dis1[xx][yy][1] == inf_int) {
                    if(vis[xx][yy] == vis[x][y]) {
                        dis1[xx][yy][1] = dis1[x][y][1] + 1;
                    }
                    else {
                        dis1[xx][yy][1] = dis1[x][y][0] + 1;
                    }
                    q1.push({k.id, xx, yy});
                }
            }
        }
    }
    // ifor(0, n-1) {
    //     jfor(0, m-1) {
    //         cout << dis1[i][j][1] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = inf_int;
    ifor(0, n-1) {
        jfor(0, m-1) {
            if(dis[i][j] < inf_int && dis1[i][j][0] < inf_int && dis1[i][j][1] < inf_int) {
                // cout << dis[i][j] << ' ' << dis1[i][j][0] << ' ' << dis1[i][j][1] << endl;
                ans = min(ans, dis[i][j] + dis1[i][j][0] + dis1[i][j][1]);
            }
        }
    }
    // cout << pre << ' ' << ans << endl;
    cout << pre - ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
