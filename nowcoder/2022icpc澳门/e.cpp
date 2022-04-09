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
    const int max_le = 297152*2+1;
    /* 预处理 sin 与 cos */
    // Complex prewn[max_le];

    /*
     * 预处理函数
     * 预处理 sin 和 cos 的值
     */
    // void init() { for(int i=1; i<=max_le; i++) { prewn[i] = Complex(cos(2/PI*i), sin(2/PI*i)); } }

    /*
     * 进行 FFT 和 IFFT 前的反置变换
     * 位置 i 和 i 的二进制反转后的位置互换
     *len 必须为 2 的幂
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
        // if(on == -1) { for(int i = 0; i < len; i++) { y[i].x /= len; y[i].y /= len; } }
    }

    /* MMT过程辅助数组 */
    Complex a[max_le], b[max_le], c[max_le], d[max_le];

    /*
     * 做 MTT
     * x1, x2 为两个多项式系数
     * len1 为第一个多项式长度
     * len2 为第二个多项式长度
     * ans 为输出的答案数组
     * flen 为调整后的长度
     * p 模数
     */
    void solve_mtt(int x1[], int x2[], int len1, int len2, ll ans[], int &flen) {
        int len = 1;
        while(len <= (len1+len2)) { len *= 2; }
        flen = len;
        for(int i=0; i<len; i++) {
            if(i < len1) { a[i] = Complex((x1[i] & 32767), (x1[i] >> 15)); }
            else { a[i] = Complex(); }
            if(i < len2) { b[i] = Complex((x2[i] & 32767), (x2[i] >> 15)); }
            else { b[i] = Complex(); }
        }
        fft(a, len, 1); fft(b, len, 1);
        for(int i=0; i<len; i++) {
            int u=(len-i)&(len-1);
            c[i]=(a[i].conj()+a[u])*Complex(.5,0)*b[u];
            d[i]=(a[i].conj()-a[u])*Complex(0,.5)*b[u];
        }
        fft(c, len, 1); fft(d, len, 1);
        for(int i=0; i<len; i++) {
            ll x=round(c[i].x/len);
            ll y=round((c[i].y+d[i].x)/len);
            ll z=round(d[i].y/len);
            ans[i] = x+(y<<15)+(z<<30);
        }
    }
};

const int N = 297152*2+1;

ll n, q;
ll pre[N];
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
            for(int j=cnt-1; j>=0; j--) { v[cnt-1-j] = u[j]; }
            int len;
            FFT::solve_mtt(u, v, cnt, cnt, pre, len);
            if(ans[cnt].size() == 0) { ans[cnt].resize(cnt); id.push_back(cnt); }
            for(int j=0; j<cnt; j++) { ans[cnt][j] += pre[j+cnt] + pre[j]; }
        }
    }
    //assert(id[0]);
    for(int i=1; i<=q; i++) {
        int tt;
        cin >> tt;
        ll res = 0;
        for(auto k: id) {
            int rr = tt % k;
            if(rr == 0) { res += ans[k][k-1]; }
            else { res += ans[k][k-1-rr]; }
            // cout << res << endl;
            // res += ans[k][rr];
        }
        cout << res << '\n';
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