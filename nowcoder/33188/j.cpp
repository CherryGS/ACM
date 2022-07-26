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

int n, cnt;
int c[5][500500];
map<pii, int> e;
int h[8000100], nx[16000200], to[16000200], w[16000200], ct;
int dis[8000100];
bool vis[8000100];

void add(cint f, cint t, cint co) {
    nx[++ct] = h[f];
    h[f] = ct;
    to[ct] = t;
    w[ct] = co;
}

int dij(int s, int t) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while(!q.empty()) {
        auto k = q.top();
        q.pop();
        if(k.second == t) { return dis[t]; }
        if(vis[k.second]) { continue; }
        vis[k.second] = 1;
        for(int i=h[k.second]; i; i=nx[i]) {
            if(dis[to[i]] > dis[k.second] + w[i]) {
                dis[to[i]] = dis[k.second] + w[i];
                q.push({dis[to[i]], to[i]});
            }
        }
    }
    return dis[t];
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { for(int j=1; j<=4; j++) { cin >> c[j][i]; } }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=4; j++) {
            if(c[j][i] && e.find({i, c[j][i]}) == e.end()) {
                e[{i, c[j][i]}] = ++cnt;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=4; j++) {
            int v = c[j][i];
            if(v) {
                int jj;
                for(int k=1; k<=4; k++) {
                    if(c[k][v] == i) { jj = k; }
                }
                for(int k=1; k<=4; k++) {
                    int vv = c[k][v];
                    if(vv) {
                        if(k == jj%4+1) {
                            add(e[{i, v}], e[{v, vv}], 0);
                        }
                        else {
                            add(e[{i, v}], e[{v, vv}], 1);
                        }
                    }
                }
            }
        }
    }
    int s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    int ans = dij(e[{s1, s2}], e[{t1, t2}]);
    cout << (ans < dis[0] ? ans : -1) << '\n';
}

int main() {
//     freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}