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

bool flag;
int n, f;
vector<int> g[100100];
vector<int> val[100100];
map<int, int> r[100100];

void dfs(cint u, cint fa) {
    int sum = 0;
    for(int v: g[u]) {
        if(v != fa) {
            dfs(v, u);
            if(r[v].size()) ++ sum;
        }
    }
    
}

void solve(cint T) {
    cin >> n >> f;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=f; i++) {
        cin >> u >> v;
        val[u].push_back(i);
        val[v].push_back(i);
    }
    dfs(1, 1);
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}