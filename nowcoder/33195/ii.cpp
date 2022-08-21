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


int n, m;
int a[1000100];
int b[1000100];
int p1[1000100];
int p2[1000100];

namespace FFT {
    typedef const int& cint;
    typedef long long ll;
    typedef float db;

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
    const int max_le = (1<<25)+1;

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
    Complex c1[max_le];

    /* FFT 加上三次变两次优化 */
    void solve_fft2(int x1[], int x2[], int len1, int len2, int ans[]) {
        int len = 1;
        while(len < (len1+len2)) { len *= 2; }
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
};

void solve(cint T) {
    int mx = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++) { cin >> a[i]; mx = max(mx, a[i]); }
    for(int i=1; i<=m; i++) { cin >> b[i]; mx = max(mx, b[i]); }
    int t[2] = {0, 0};
    for(int i=1; i<=n; i++) {
        if(p1[a[i]] == 1) { t[0] = i; }
        p1[a[i]] = 1;
    }
    for(int i=1; i<=m; i++) {
        if(p2[b[i]] == 1) { t[1] = i; }
        p2[b[i]] = 1;
    }
    if(t[0] != 0 && t[1] != 0) {
        int s[2] = {0, 0};
        for(int i=1; i<=n; i++) {
            if(a[t[0]] == a[i] && i != t[0]) { s[0] = i; }
        }
        for(int i=1; i<=m; i++) {
            if(b[t[1]] == b[i] && i != t[1]) { s[1] = i; }
        }
        cout << t[0] << ' ' << s[0] << ' ' << t[1] << ' ' << s[1] << '\n';
    }
    else {
        // cout << " --- " << endl;
        FFT::solve_fft2(p1, p2, mx+1, mx+1, p1);
        // for(int i=0; i<=mx; i++) { cout << p1[i] << ' '; }
        // cout << endl;
        int id = -1;
        for(int i=0; i<=mx*2; i++) {
            if(p1[i] > 1) { id = i; break; }
        }
        // cout << id << endl;
        if(id == -1) { cout << -1 << '\n'; return; }
        memset(p1, 0, sizeof p1);
        for(int i=1; i<=m; i++) { p1[b[i]] = i; }
        int t[2] = {0, 0}, s[2] = {0, 0};
        for(int i=1; i<=n; i++) {
            if(a[i] <= id && p1[id-a[i]] != 0) {
                t[0] = i;
                t[1] = p1[id-a[i]];
                break;
            }
        }
        memset(p1, 0, sizeof p1);
        for(int i=1; i<=n; i++) { p1[a[i]] = i; }
        for(int i=1; i<=m; i++) {
            if(b[i] <= id && p1[id-b[i]] != 0) {
                s[0] = p1[id-b[i]];
                s[1] = i;
                break;
            }
        }
        cout << t[0] << ' ' << s[0] << ' ' << t[1] << ' ' << s[1] << '\n';
    }
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