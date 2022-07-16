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
    typedef const int& cint;
    typedef long long ll;
    typedef long double db;

    struct Complex {
        db x, y;
        Complex(db _x = 0.0, db _y = 0.0) { x = _x; y = _y; }
        Complex conj() { return Complex(x, -y); }
        Complex operator!() { return Complex(x, -y); }
        Complex operator-(const Complex &b) const { return Complex(x - b.x, y - b.y); }
        Complex operator+(const Complex &b) const { return Complex(x + b.x, y + b.y); }
        Complex operator*(const db&b) const { return Complex(x*b, y*b); }
        Complex operator*(const Complex &b) const { return Complex(x * b.x - y * b.y, x * b.y + y * b.x); }
    };

    /* PI 的值 */
    const db PI = acos(-1.0);
    /* 最大长度 , 保证补充到了 2 的次幂 */
    const int max_le = (1<<19)+1;

    /*
     * 进行 FFT 和 IFFT 前的反置变换
     * 位置 i 和 i 的二进制反转后的位置互换
     * len 必须为 2 的幂
     */
    void change(Complex y[], cint len) {
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
    void fft(Complex y[], cint len, cint on) {
        change(y, len); 
        for(int h = 2; h <= len; h <<= 1) {
            /* 使用预处理的 sin 和 cos */
            // Complex wn = prewn[h];
            // wn.y *= on;

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

    /* MMT过程辅助数组 */
    Complex a[max_le], b[max_le], c[max_le], d[max_le];

    /*
     * 做 MTT
     * x1, x2 为两个多项式系数
     * len1 , len2 为输入数组长度 , 注意下标从 0 开始 , 所以按 [0,len) 计算
     * ans 为输出的答案数组
     * flen 为调整后的长度
     * p 模数
     */
    void solve_mtt(int x1[], int x2[], int len1, int len2, ll ans[], int& flen) {
        int len = 1;
        while (len < (len1+len2)) { len *= 2; }
        flen = len;
        for(int i=0; i<len; i++) {
            if(i < len1) { a[i] = Complex((x1[i] & ((1<<17)-1)), (x1[i] >> 17)); }
            else { a[i] = Complex(); }
            if(i < len2) { b[i] = Complex((x2[i] & ((1<<17)-1)), (x2[i] >> 17)); }
            else { b[i] = Complex(); }
        }
        fft(a, len, 1); fft(b, len, 1);
        for(int i=0; i<len; i++) {
            int j = (i==0?0:len-i);
            c[j] = Complex(a[i].x+a[j].x,a[i].y-a[j].y)*db(0.5)*b[i];
            d[j] = Complex(a[i].y+a[j].y,a[j].x-a[i].x)*db(0.5)*b[i];
        }
        fft(c, len, 1); fft(d, len, 1);
        for(int i=0; i<len; i++) {
            ll x=ll(round(c[i].x/len));
            ll y=ll(round(c[i].y/len));
            ll u=ll(round(d[i].x/len));
            ll v=ll(round(d[i].y/len));
            ans[i] = (x+((y+u)<<17)+(v<<34));
        }
    }
};

int n;
int f[100100];
int c[100100];
int a[100100], b[100100];
const int lim = (1<<19)+1;
ll ans[lim], ans1[lim];
ll pre[lim];

void sol() {
    memset(pre, 0, sizeof pre);
    memset(ans, 0, sizeof ans);
    sort(f+1, f+1+n);
    sort(c+1, c+1+n, [] (cint x, cint y) { return x > y; } );
    int l = 1, r = n, cnt = 0;
    while(l <= r) {
        ll mn1 = 1, mn2 = 1;
        mn1 = min(mn1, 1ll * f[l] * c[l]);
        mn2 = min(mn2, 1ll * f[r] * c[r]);
        if(mn1 < mn2) {
            if(mn1 < 1) {
                ans[cnt + 1] = ans[cnt] + mn1;
                cnt += 1;
                ++l;
            }
            else { break; }
        }
        else if(mn1 >= mn2) {
            if(mn2 < 1) {
                ans[cnt + 1] = ans[cnt] + mn2;
                cnt += 1;
                --r;
            }
            else { break; }
        }
    }
    for(int i=l; i<=r; i++) {
        a[i-l] = f[i];
        b[i-l] = c[r+l-i];
    }
    if(a[0] < 0) { reverse(a, a+r-l+1); }
    if(b[0] < 0) { reverse(b, b+r-l+1); }
    int len;
    ll now = ans[cnt];
    FFT::solve_mtt(a, b, r-l+1, r-l+1, pre, len);
    for(int i=1; i<=len; i++) { ans[cnt+1] = now + pre[i-1]; ++cnt; }
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> f[i]; }
    for(int i=1; i<=n; i++) { cin >> c[i]; }
    sol();
    for(int i=1; i<=n; i++) { ans1[i] = ans[i]; }
    for(int i=1; i<=n; i++) { c[i] = -c[i]; }
    sol();
    for(int i=1; i<=n; i++) {
        cout << ans1[i] << ' ' << -ans[i] << '\n';
    }
    cout << endl;
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