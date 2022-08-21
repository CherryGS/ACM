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

const int mod1 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

namespace NTT {
    typedef long long ll;

    /* 常见原根表 */
    // 998244353 -> 3
    const int P = 998244353, G = 3;

    /* 最大长度 , 保证补充到了 2 的次幂 */
    const int max_le = (1<<21)+1;

    int w[max_le], inv[max_le];

    int mod(int x) { return x >= P ? x - P : x; }

    ll ksm(ll bs, int x) {
        ll ans = 1;
        while(x) {
            if(x & 1) { ans = ans * bs % P; }
            bs = bs * bs % P;
            x >>= 1;
        }
        return ans;
    }
 
    void init(int len) {
        inv[1] = 1;
        for(int i=2;i<=len;i++) { inv[i] = mod(P - 1ll * (P / i) * inv[P%i] % P); }
        for(int i=1;i<len;i<<=1) {
            int wn = ksm(G, (P - 1) / (i<<1));
            for(int j=0, ww=1; j<i; j++, ww=1ll*ww*wn%P) { w[i+j] = ww; }
        }
    }
    
    void change(ll y[], int len) {
        int i, j, k;
        for (i = 1, j = len / 2; i < len - 1; i++) {
            if(i < j) { swap(y[i], y[j]); }
            k = len / 2;
            while (j >= k) { j = j - k; k = k / 2; }
            if(j < k) { j += k; }
        }
    }
 
    void ntt(ll f[], int len, int op) {
        change(f, len);
        for(int i=1;i<len;i<<=1){
            for(int j=0;j<len;j+=i<<1) {
                for(int k=0;k<i;k++) {
                    int x = f[j+k], y = 1ll * f[i+j+k]* w[i+k]%P;
                    f[j+k] = mod(x+y);
                    f[i+j+k] = mod(x-y+P);
                }
            }
        }
        if(op == -1) {
            reverse(&f[1],&f[len]);
            for(int i=0;i<len;i++) { f[i] = 1ll * f[i] * inv[len] % P; };
        }
    }
    /* NTT 过程辅助数组 */
    ll a[max_le], b[max_le];

    void solve(ll x1[], ll x2[], int len1, int len2, ll ans[]) {
        int len = 1;
        while(len < (len1 + len2)) { len <<= 1; }
        init(len);
        for(int i=0; i<len; i++) {
            if(i < len1) { a[i] = x1[i]; }
            else { a[i] = 0; }
            if(i < len2) { b[i] = x2[i]; }
            else { b[i] = 0; }
        }
        ntt(a, len, 1); ntt(b, len, 1);
        for(int i=0; i<len; i++) { a[i] = a[i] * b[i] % P; }
        ntt(a, len, -1);
        for(int i=0; i<len; i++) { ans[i] = a[i]; }
    }
};

int n, k;
int p[500500];
int vis[500500];
int f[500500];
int inv[500500];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod1; }
        bs = bs * bs % mod1;
        x >>= 1;
    }
    return ans;
}

void init() {
    f[0] = 1;
    for(int i=1; i<=500000; i++) { f[i] = 1ll * f[i-1] * i % mod1; }
    inv[500000] = ksm(f[500000], mod1-2);
    for(int i=500000-1; i>=0; i--) { inv[i] = 1ll * inv[i+1] * (i+1) % mod1; }
}

ll C(int n, int m) {
    if(n < m || m < 0) { return 0; }
    return 1ll * f[n] * inv[m] % mod1 * inv[n-m] % mod1;
}

ll cacu(int n, int m) {
    // cout << C(n-m-1, m-1) << ' ' << C(n-m, m) << ' ' << n << ' ' << m << endl;
    return (C(n-m-1, m-1) + C(n-m, m)) % mod1;
}

ll pre[1000100];
ll ans[1000100];

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> p[i]; }
    memset(vis, 0, sizeof vis);
    memset(ans, 0, sizeof ans);
    vector<pii> q;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            int r = i;
            int s = 1;
            while(p[r] != i) {
                ++s;
                r = p[r];
                vis[r] = 1;
            }
            q.push_back({s, i});

            // for(int j=1; j<=n; j++) { cout << ans[j] << ' '; }
            // cout << endl;
        }
    }
    sort(q.begin(), q.end());
    int sum = 0;
    for(int i=0; i<q.size(); i++) {
        int s = q[i].first;
        if(i == 0) {
            for(int j=0; j<=s; j++) { ans[j] = cacu(s, j); }
            sum = s;
        }
        else {
            if(s == 1) { continue; }
            for(int j=0; j<=s; j++) { pre[j] = cacu(s, j); }
            NTT::solve(ans, pre, min(sum, k)+1, min(s, k)+1, ans);
            sum += s;
        }
    }
    cout << ans[k] << '\n';
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