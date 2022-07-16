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

int p;
int dep[200200];
int val[200020];
int h[200020], nx[400040], to[400040], w[400040], cnt;
int num=1;

void add(int f, int t) {
    nx[++cnt] =  h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for(int i=h[u]; i; i=nx[i]) {
        if(to[i] != fa) {
            if(dep[u]&1) {
                w[i] = w[i^1] = (1<<p) + num;
                val[to[i]] = num;
            }
            else {
                w[i] = w[i^1] = num;
                val[to[i]] = (1<<p) + num; 
            }
            ++num;
            dfs(to[i], u);
        }
    }
}

void solve(cint T) {
    num = 1;
    cnt = 1;
    cin >> p;
    int u, v;
    for(int i=1; i<=(1<<p); i++) { dep[i] = h[i] = 0; }
    for(int i=1; i<(1<<p); i++) { 
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    val[1] = 1<<p;
    dfs(1, 1);
    cout << 1 << '\n';
    for(int i=1; i<=(1<<p); i++) { cout << val[i] << ' '; }
    cout << '\n';
    for(int i=2; i<=cnt; i+=2) { cout << w[i] << ' '; }
    cout << '\n';
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