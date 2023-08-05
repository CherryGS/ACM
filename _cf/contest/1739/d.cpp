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

int n, k;
vector<int> to[200200];
int dp[200200];
int f[200200];

void dfs(int u, int fa, int &x, int &sum) {
    dp[u] = 0;
    for(int &v: to[u]) {
        if(v != fa) {
            dfs(v, u, x, sum);
            dp[u] = max(dp[u], dp[v]+1);
        }
    }
    if(dp[u] == x-1 && f[u] != 1) { ++sum; dp[u] = -1;}
}

bool check(int x) {
    int sum = 0;
    dfs(1, 1, x, sum);
    // cout << sum << ' ' << x << endl;
    return sum <= k;
}

bool solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { to[i].clear(); }
    int fa;
    f[1] = 1;
    for(int i=1; i<n; i++) {
        cin >> f[i+1];
        to[f[i+1]].push_back(i+1);
        to[i+1].push_back(f[i+1]);
    }
    int l = 1, r = n, mid;
    while(l < r) {
        mid = l + ((r-l)>>1);
        if(check(mid)) { r = mid; }
        else { l = mid + 1; }
    }
    cout << r << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}