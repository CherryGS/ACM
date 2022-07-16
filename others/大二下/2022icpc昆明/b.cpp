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
bool ok[1<<10];
bool vis[1<<10];
int dp[1<<10];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod2; }
        bs = bs * bs % mod2;
        x >>= 1;
    }
    return ans;
}

struct node {
    int l, r, u, d;
    void init() { cin >> l >> d >> r >> u; }
    bool operator < (const node&a) const { return l < a.l; }
};

bool check(int x) {

}

void solve(cint T) {
    node e[11];
    memset(ok, 0, sizeof ok);
    memset(vis, 0, sizeof vis);
    memset(dp, 0, sizeof dp);
    cin >> n;
    for(int i=1; i<=n; i++) { e[i].init(); }
    sort(e+1, e+1+n);
    queue<int> q;
    q.push((1<<n)-1);
    while(!q.empty()) {
        int t = q.front();
        if(!ok[t] && !check(t)) { ok[t] = 1; }
        q.pop();
        int r = __popcount(t);
        for(int l=0; (1<<l) <= t; l++) if(t & (1<<l)) {
            int j = t ^ (1<<l);
            if(!vis[j]) {
                vis[j] = 1;
                q.push(j);
            }
            if(ok[t] == 1) { 
                ok[j] = 1; 
                dp[j] = 1ll + dp[j] + dp[t] ;
            }
        }
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