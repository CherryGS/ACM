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

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) { 
        if(x&1) ans = ans * bs % mod2;
        bs = bs * bs % mod2;
        x >>= 1;
    }
    return ans;
}

int n;
ll p[1000100], c[1000100];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n;
        ll sum = 0;
        for(int i=1; i<=n; i++) cin >> p[i] >> c[i];
        for(int i=1; i<=n; i++) sum += c[i];
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ans += (ksm(p[i], sum) * ksm(sum, mod2-2)) % mod2;
            ans %= mod2;
        }
        cout << ans << endl;
    }
    return 0;
}