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

ll n;

ll get_fac(ll x) {
    for(ll i = 3; i <= sqrt(x); i+=2) {
        if(!(x%i)) return i;
    }
    return -1;
}

void solve(cint T) {
    cin >> n;
    if(n&1) { cout << 2 << '\n'; return; }
    ll x = n;
    int r = 0;
    while(!(x&1)) { ++ r; x >>= 1; }
    if(((x-1)>>1) < (1ll << r)) {
        ll val = -1;
        if(val == -1 && ((x+1)>>1) <= (1ll << r) && x != 1) { val = x; }
        else { val = get_fac(x); }
        cout << val << '\n';
    }
    else { cout << (1ll<<(r+1)) << '\n'; return; }
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}