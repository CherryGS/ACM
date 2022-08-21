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

int n, q;
int siz[100100];
ll sum[2][100100];
vector<int> to[100100];

void dfs1(int u, int fa) {
    siz[u] = 1;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs1(v, u);
            siz[u] += siz[v];
        }
    }
}

void cacu(int u, int fa, ll s1, ll s2) {
    int t = u;
    ll p1 = 0, p2 = 0;
    while(t % 2 == 0) { t /= 2; ++p1; }
    while(t % 5 == 0) { t /= 5; ++p2; }
    s1 = s1 + p1 * siz[u];
    s2 = s2 + p2 * siz[u];
    sum[0][u] = s1;
    sum[1][u] = s2;
    for(int &v: to[u]) {
        if(v != fa) {
            cacu(v, u, s1-p1*siz[v], s2-p2*siz[v]);
        }
    }
}

void solve(cint T) {
    cin >> n >> q;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs1(1, 1);
    cacu(1, 1, 0, 0);
    int x;
    for(int i=1; i<=q; i++) {
        cin >> x;
        cout << min(sum[0][x], sum[1][x]) << '\n';
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}