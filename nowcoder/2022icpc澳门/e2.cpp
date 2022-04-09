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

namespace FFT {
    typedef long long ll;
    typedef long double db;

    struct Complex {
        db x, y;
        Complex(db _x = 0.0, db _y = 0.0) { x = _x; y = _y; }
        Complex operator!() { return Complex(x, -y); }
        Complex operator-(const Complex &b) const { return Complex(x - b.x, y - b.y); }
        Complex operator+(const Complex &b) const { return Complex(x + b.x, y + b.y); }
        Complex operator*(const Complex &b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
    };

    /* PI 的值 */
    const db PI = acos(-1.0);
    /* 最大长度 , 保证补充到了 2 的次幂 */
    const int max_le = 297152*2+1;

    /*
     * 进行 FFT 和 IFFT 前的反置变换
     * 位置 i 和 i 的二进制反转后的位置互换
     * len 必须为 2 的幂
     */
    void change(Complex y[], int len) {
        int i, j, k;
        for (i = 1, j = len / 2; i < len - 1; i++) {
            if(i < j) { swap(y[i], y[j]); }
            k = len / 2;
            while (j >= k) { j = j - k; k = k / 2; }
            if(j < k) { j += k; }
        }
    }

    /*
     * 做 FFT
     * len 必须是 2^k 形式
     * on == 1 时是 DFT，on == -1 时是 IDFT
     */
    void fft(Complex y[], int len, int on) {
        change(y, len); 
        for(int h = 2; h <= len; h <<= 1) {
            /* 不使用预处理的 sin 和 cos */
            Complex wn(cos(2 * PI / h), sin(2 * PI / h) * on);

            for(int j = 0; j < len; j += h) {
                Complex w(1, 0);
                for (int k = j; k < j + h / 2; k++) {
                    Complex u = y[k];
                    Complex t = w * y[k + h / 2];
                    y[k] = u + t;
                    y[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        /* 这里将实部和虚部都从点值转换成了系数 */
        if(on == -1) { for(int i = 0; i < len; i++) { y[i].x /= len; y[i].y /= len; } }
    }

    /* FFT过程辅助数组 */
    Complex c1[max_le], c2[max_le];

    /*
     * 做 FFT
     * x1,x2为输入数组
     * ans 为答案数组 , flen 为最后长度
     * ans 只会在过程最后被修改
     */
    void solve_fft(int x1[], int x2[], int len1, int len2, ll ans[], int&flen) {
        int len = 1;
        while (len < len1 * 2 || len < len2 * 2) { len *= 2; }
        flen = len;
        for(int i=0; i<len1; i++) { c1[i] = Complex(x1[i], 0); }
        for(int i=len1; i<len; i++) { c1[i] = Complex(); }
        for(int i=0; i<len2; i++) { c2[i] = Complex(x2[i], 0); }
        for(int i=len2; i<len; i++) { c2[i] = Complex(); }
        fft(c1, len, 1);
        fft(c2, len, 1);
        for(int i=0; i<len; i++) { c1[i] = c1[i] * c2[i]; }
        fft(c1, len, -1);
        for(int i=0; i<len; i++) { ans[i] = ll(c1[i].x + 0.5); }
    }
};

const int N = 297152+1;

ll n, q;
ll pre[N*2];
int p[N];
int cnt;
int u[N];
int v[N];
bool vis[N];
vector<ll> ans[100100];

void solve(cint T) {
    cin >> n >> q;
    vector<int> id;
    for(int i=1; i<=n; i++) { cin >> p[i]; }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cnt = 0;
            int r = i;
            while(!vis[r]) {
                u[cnt] = r;
                ++cnt;
                vis[r] = 1;
                r = p[r];
            }
            // for(int j=0; j<cnt; j++) { cout << u[j] << ' '; } cout << endl;
            for(int j=cnt-1; j>=0; j--) { v[cnt+cnt-1-j] = v[cnt-1-j] = u[j]; }
            for(int j=cnt-1; j>=0; j--) { u[j + cnt] = 0; }
            int len;
            FFT::solve_fft(u, v, cnt, cnt*2, pre, len);
            if(ans[cnt].size() == 0) { ans[cnt].resize(cnt); id.push_back(cnt); }
            for(int j=0; j<cnt; j++) { ans[cnt][j] += pre[j+cnt-1]; }
        }
    }
    // cout << sum << endl;
    // for(auto k: id) {
    //     cout << k << " --- " << endl;
    //     for(auto kk: ans[k]) {
    //         cout << kk << ' ';
    //     }
    //     cout << endl;
    // }
    int tt;
    for(int i=1; i<=q; i++) {
        cin >> tt;
        ll res = 0;
        for(auto k: id) {
            int rr = tt % k;
            res += ans[k][rr];
        }
        cout << res << '\n';
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