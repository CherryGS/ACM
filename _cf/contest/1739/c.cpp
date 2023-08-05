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

int n;
int to[101];
int inv[101];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs % mod; }
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

void init() {
    to[0] = 1;
    for(int i=1; i<=100; i++) { to[i] = 1ll * to[i-1] * i % mod; }
    inv[100] = ksm(to[100], mod-2);
    for(int i=100-1; i>=0; i--) { inv[i] = 1ll * inv[i+1] * (i+1) % mod; }
}

ll C(int n, int m) {
    return 1ll * to[n] * inv[m] % mod * inv[n-m] % mod;
}

bool solve(cint T) {
    cin >> n;
    ll all = C(n, n/2);
    ll a[2][2] = {0, 0, 0, 0};
    bool st = 0;
    a[0][0] = 1;
    for(int i=4; i<=n; i+=2, st ^= 1) {
        a[st^1][0] = (a[st][1] + C(i-1, i/2)) % mod;
        a[st^1][1] = (C(i, i/2)-1-a[st^1][0]+mod) % mod;
    }
    cout << a[st][0] << ' ' << a[st][1] << ' ' << 1 << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}