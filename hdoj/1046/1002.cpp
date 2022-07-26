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

int n;
ll h;
int t[100], len[100];
int pre[1<<18];
ll d[20][100100];
ll dp[1<<18];

ll cacu(int x, int t, int i) {
    if(pre[x] >= t) { return 0; }
    // cout << x << ' ' << t << ' ' << i << ' ' << pre[x] << endl;
    int dt = t - pre[x];
    return d[i][min(len[i], dt)];
}

ll dfs(int x, int t) {
    if(x == 0) { return 0; }
    if(dp[x]) { return dp[x]; }
    for(int i=0; (1<<i) <= x; i++) {
        if(x & (1<<i)) {
            dp[x] = max(dp[x], dfs(x ^ (1<<i), t) + cacu(x ^ (1<<i), t, i+1));
        }
    }
    return dp[x];
}

bool check(int x) {
    for(int i=1; i<(1<<n); i++) { dp[i] = 0; }
    return dfs((1<<n)-1, x) >= h;
}

void init() {
    for(int i=1; i<(1<<n); i++) {
        pre[i] = 0;
        for(int j=0; (1<<j) <= i; j++) {
            if(i & (1<<j)) {
                pre[i] += t[j+1];
            }
        }
    }
}

void solve(cint T) {
    cin >> n >> h;
    int sum_t = 0;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> len[i];
        sum_t += t[i] + len[i];
        for(int j=1; j<=len[i]; j++) { cin >> d[i][j]; d[i][j] += d[i][j-1]; }
    }
    init();
    int l = 1, r = sum_t + 1, mid;
    while(l < r) {
        mid = l + ((r-l)>>1);
        if(check(mid)) { r = mid; }
        else { l = mid + 1; }
    }
    if(r == sum_t + 1) { cout << -1 << '\n'; }
    else { cout << r-1 << '\n'; }
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