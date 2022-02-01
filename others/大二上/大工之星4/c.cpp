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

ll x, y, z, l;

ll ksm(ll bs, int x, ll mod) {
    ll ans = 1;
    while(x) {
        if(x&1) ans = ans * bs % mod;
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

bool check(ll x, ll y, ll z, ll l, ll mod) {
    return (ksm(x, l, mod1) + ksm(y, l, mod1)) % mod1 == ksm(z, l, mod1);
}

void solve(cint T) {
    cin >> x >> y >> z >> l;
    if(check(x, y, z, l, mod1)) cout << 1 << '\n';
    else cout << -1 << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}