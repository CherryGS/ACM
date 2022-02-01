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
ll pre[1000100];
ll sr;

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) ans = ans * bs % mod2;
        bs = bs * bs % mod2;
        x >>= 1;
    }
    return ans;
}

void init() {
    sr = ksm(2, mod2-2);
    pre[0] = 1;
    for(int i=1; i<=1000000; i++) pre[i] = pre[i-1] * i % mod2;
}

void solve(cint T) {
    cin >> n;
    if(n&1) cout << (n-1)/2*n%mod2*pre[n]%mod2*sr%mod2 << endl;
    else cout << n/2*(n-1)%mod2*pre[n]%mod2*sr%mod2 << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}