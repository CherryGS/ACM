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

const int N = (1<<18) + 1;
int n;
int len = 1;
ll a[100100];
ll pre[N];
ll ans[N];

void cdq(cint l, cint r) {
    if(l == r) { return; }
    int mid = (l+r) >> 1;
    cdq(l, mid);
    NTT::solve(ans+l, a, mid+1-l, r-l+1, pre);
    for(int i=mid+1; i<=r; i++) { (ans[i] += pre[i-l]) %= mod2;  }
    cdq(mid+1, r);
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<n; i++) { cin >> a[i]; }
    ans[0] = 1;
    cdq(0, n-1);
    for(int i=0; i<n; i++) { cout << ans[i] << ' '; }
    cout << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}