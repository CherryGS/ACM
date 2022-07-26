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
int f[600600];

struct Play {
    const int mod = 998244353;
    int h[600300];
    void init(int* x, int t) {
        memset(h, 0, sizeof(int) * (t+1));
        for(int i=1; i<=t; i++) { h[i] = (10ll * h[i-1] + x[i]) % mod; }
    }
    int get_h(int l, int r) {
        return (1ll + h[r] - (1ll * h[l-1] * f[r-l+1]) % mod + mod) % mod;
    }
} S, P, Q;

int p[300300];
int q[300300];
int s[600600];
int p1[300300];
int q1[300300];
int sum[300300];
int to[2][300300];

void init() {
    f[0] = 1;
    for(int i=1; i<=600000; i++) { f[i] = f[i-1] * 10 % mod2; }
}

bool check(int x, int l, int r) {
    bool st = 0;
    if(x == n*2+1 && l == n+1 && r == n+1) { return true; }
    if(l <= n && s[x] == p[l]) { st |= check(x+1, l+1, r); }
    if(st) { return true; }
    if(r <= n && s[x] == q[r]) { st |= check(x+1, l, r+1); }
    if(st) { return true; }
    return false;
}

void solve(cint T) {
    cin >> n;
    bool flag = true;
    for(int i=1; i<=n; i++) { to[0][i] = to[1][i] = sum[i] = 0; }
    for(int i=1; i<=n; i++) { cin >> p[i]; p1[p[i]] = i; }
    for(int i=1; i<=n; i++) { cin >> q[i]; q1[q[i]] = i;}
    for(int i=1; i<=n; i++) { if(p[i] != q[i]) { flag = false; break; } }
    for(int i=1; i<=n*2; i++) { 
        cin >> s[i]; 
        sum[s[i]]++;
        if(to[0][s[i]] == 0) { to[0][s[i]] = i; }
        else { to[1][s[i]] = i; } 
    }
    for(int i=1; i<=n; i++) { if(sum[i] != 2) { cout << 0 << '\n'; return; } }
    S.init(s, n*2);
    P.init(p, n);
    Q.init(q, n);
    ll ans = check(1, 1, 1);
    for(int i=1; i<n*2; i++) {
        if(to[1][s[i+1]] != i+1) { continue; }
        int l = i+1-to[0][s[i+1]];
        if(i+l > n*2) { continue; }
        int hs = S.get_h(i-l+1, i);
        // cout << i << ' ' << i-l+1 << ' ' << l << ' ' << i+1 << ' ' << i+l << endl;
        // cout << hs << ' ' << S.get_h(i+1, i+l) << endl;
        if(hs != S.get_h(i+1, i+l)) { continue; }
        if(l) {
            if(P.get_h(p1[s[i+1]], p1[s[i+1]]+l-1) == hs && Q.get_h(q1[s[i+1]], q1[s[i+1]]+l-1) == hs) {
                for(int j=0; j<l; j++) { p[p1[s[i+1]]+j] = 0; }
                for(int j=0; j<l; j++) { q[q1[s[i+1]]+j] = 0; }
                fill(s+(i-l+1), s+(i+l)+1, 0);
                ans = ans * 2 % mod2;
            }
        }
    }
    // for(int i=1; i<=n; i++) { cout << p[i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n; i++) { cout << q[i] << ' '; }
    // cout << endl;
    // for(int i=1; i<=n*2; i++) { cout << s[i] << ' '; }
    // cout << endl;
    // cout << ans << endl;
    for(int i=1; i<=n; i++) { if(!flag) { break; } if(p[i] != 0) { break; } if(i == n) { flag = false; } }
    cout << (ans * (flag ? 2 : 1)) % mod2 << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}