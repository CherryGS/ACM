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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m, p;
ll f[34][17];
ll fac[34];

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) { ans = ans * bs; }
        bs = bs * bs;
        x >>= 1;
    }
    return ans;
}

bool solve(cint T) {
    fac[0] = 1;
    cin >> m >> n >> p;
    for(int i=1; i<=n; i++) { fac[i] = fac[i-1] * i; }
    f[0][0] = 1;
    for(int i=1; i<=p; i++) {
        for(int j=1; j<=n; j++) {
            f[i][j] += f[i-1][j-1]*2 + f[i-1][j]*(m-2*(j!=n));
        }
    }
    ll pre1 = f[p][n] * fac[n];
    cout << f[p][n] << endl;
    ll pre2 = ksm(m, p);
    ll frac = gcd(pre1, pre2);
    cout << pre1/frac << '/' << pre2/frac << '\n';
    return true;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}