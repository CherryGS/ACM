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

const int mx_n = 10000;
int vis[mx_n+1000];
int prim[mx_n+1000], cnt;
ll ans[200200];

void liner_sieve() {
    int rt = 0;
    int x = mx_n;
    for(int i=2; i<=x; i++) {
        if(!vis[i]) {
            prim[++cnt] = i;
            vis[i] = i;
        }
        for(int j=1; j<=cnt; j++) {
            if(1ll*prim[j]*i > x) break;
            if(prim[j] > vis[i]) break;
            vis[prim[j]*i] = prim[j];
        }
    }
}

const ll lim = 2e13;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) ans = ans * bs;
        bs = bs * bs;
        x >>= 1;
        if(bs > lim) return -1;
    }
    return ans;
}

ll deal(int x) {
    vector<int> q(1000, 0);
    int cnt = 0;
    while(x > 1) {
        ++ q[vis[x]];
        x /= vis[x];
    }
    vector<int> e;
    for(int i: q) if(i > 0) e.push_back(i);
    sort(e.begin(), e.end());
    int r = e.size() - 1;
    ll pre = 1;
    for(int i=0; i<=r; i++) {
        pre *= ksm(prim[i+1], e[r-i]-1);
        if(pre < 0) break;
    }
    return pre;
}

void solve(cint T) {
    int n = 1010;
    for(int i=2; i<=4; i++) cout << deal(i) << endl;
    // return;
    for(int i=2; i<=n; i++) ans[i] = deal(i);
    for(int i=n-1; i>=1; i--) {
        if(ans[i+1] > 0) {
            if(ans[i] < 0) ans[i] = ans[i+1];
            else ans[i] = min(ans[i], ans[i+1]);
        }
    }
    int k;
    cin >> k;
    cout << ans[k] << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    liner_sieve();
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}