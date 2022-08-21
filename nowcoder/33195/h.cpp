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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int A, a[8];
int B, b[8];
int to[20001000];
int inv[20000100];


ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod; }
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

ll C(int n, int m) {
    return 1ll * to[n] * inv[m] % mod * inv[n-m] % mod;
}

void init() {
    to[0] = 1;
    for(int i=1; i<=20000000; i++) { to[i] = 1ll * to[i-1] * i % mod; }
    inv[20000000] = ksm(to[20000000], mod-2);
    for(int i=20000000-1; i>=0; i--) { inv[i] = 1ll * inv[i+1] * (i+1) % mod; }
}

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x%y); }

void solve(cint T) {
    cin >> A;
    for(int i=1; i<=7; i++) { cin >> a[i]; }
    cin >> B;
    for(int i=1; i<=7; i++) { cin >> b[i]; }
    int x = (A+9)/10;
    int y = (B+9)/10;
    // for(int i=1; i<=7; i++) {
    //     x += (a[i]+9)/10;
    //     y += (b[i]+9)/10;
    // }
    ll sum = 0;
    for(int i=0; i<x; i++) { sum += C(y+i-1, i) * ksm(ksm(2, y+i), mod-2); sum %= mod; }
    // cout << sum << ' ' << C(x+y, x) << endl;
    // int r = gcd(sum, C(x+y, x));
    // cout << sum/r << ' ' << C(x+y, x)/r << endl;
    // cout << sum * ksm(C(x+y, x), mod-2) % mod << '\n';
    cout << sum << '\n';
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}