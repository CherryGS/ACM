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

    /* FFT过程辅助数组 */
    Complex c1[max_le], c2[max_le];

    /*
     * 做 FFT
     * x1,x2为输入数组 , 其长度需要都不小于最近的 2 的次幂
     * len1 , len2 为输入数组长度 , 注意下标从 0 开始 , 所以按 [0,len) 计算
     * ans 为答案数组 , flen 为最后长度
     * ans 只会在过程最后被修改
     */
    void solve_fft(int x1[], int x2[], int len1, int len2, int ans[], int&flen) {
        int len = 1;
        while(len < (len1+len2)) { len *= 2; }
        flen = len;
        for(int i=0; i<len; i++) {
            if(i < len1) { c1[i] = Complex(x1[i], 0); }
            else { c1[i] = Complex(); }
            if(i < len2) { c1[i] = Complex(x2[i], 0); }
            else { c2[i] = Complex(); }
        }
        fft(c1, len, 1);
        fft(c2, len, 1);
        for(int i=0; i<len; i++) { c1[i] = c1[i] * c2[i]; }
        fft(c1, len, -1);
        for(int i=0; i<len; i++) { ans[i] = int(c1[i].x + 0.5); }
    }

    /* FFT 加上三次变两次优化 */
    void solve_fft2(int x1[], int x2[], int len1, int len2, int ans[], int&flen) {
        int len = 1;
        while(len < (len1+len2)) { len *= 2; }
        flen = len;
        for(int i=0; i<len; i++) {
            if(i < len1 && i < len2) { c1[i] = Complex(x1[i], x2[i]); }
            else if(i < len1) { c1[i] = Complex(x1[i], 0); }
            else if(i < len2) { c1[i] = Complex(0, x2[i]); }
            else c1[i] = Complex(0, 0);
        }
        fft(c1, len, 1);
        for(int i=0; i<len; i++) { c1[i] = c1[i] * c1[i]; }
        fft(c1, len, -1);
        for(int i=0; i<len; i++) { ans[i] = int(c1[i].y/2 + 0.5); }
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
    void solve_mtt(int x1[], int x2[], int len1, int len2, int ans[], int &flen, cint p) {
        int len = 1;
        while (len < (len1+len2)) { len *= 2; }
        flen = len;
        for(int i=0; i<len; i++) {
            if(i < len1) { a[i] = Complex((x1[i] & 32767), (x1[i] >> 15)); }
            else { a[i] = Complex(); }
            if(i < len2) { b[i] = Complex((x2[i] & 32767), (x2[i] >> 15)); }
            else { b[i] = Complex(); }
        }
        fft(a, len, 1); fft(b, len, 1);
        for(int i=0; i<len; i++) {
            int j = (i==0?0:len-i);
            c[j] = Complex(a[i].x+a[j].x,a[i].y-a[j].y)*0.5*b[i];
            d[j] = Complex(a[i].y+a[j].y,a[j].x-a[i].x)*0.5*b[i];
        }
        fft(c, len, 1); fft(d, len, 1);
        for(int i=0; i<len; i++) {
            ll x=ll(round(c[i].x/len))%p;
            ll y=ll(round(c[i].y/len))%p;
            ll u=ll(round(d[i].x/len))%p;
            ll v=ll(round(d[i].y/len))%p;
            ans[i] = (x+((y+u)<<15)%p+(v<<30)%p)%p;
        }
    }
};

const int MAXN = 2097153;
int x1[MAXN], x2[MAXN];
int sum[MAXN];
int n, m;

void solve(cint T) {
    cin >> n >> m;
    for(int i=0; i<=n; i++) { cin >> x1[i]; }
    for(int i=0; i<=m; i++) { cin >> x2[i]; }
    int len;
    FFT::solve_fft2(x1, x2, n+1, m+1, sum, len);
    for(int i=0; i<=n+m; i++) { cout << sum[i] << ' ';}
    cout << '\n';
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