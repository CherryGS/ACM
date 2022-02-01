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

int n;
const int mod = 100003;
ll a[10010], b[10010];

ll ksm(ll bs, int x) {
    ll ans = 1;
    while(x) {
        if(x & 1) ans = ans * bs % mod;
        bs = bs * bs % mod;
        x >>= 1;
    }
    return ans;
}

void solve(cint T) {
    cin >> n;
    ll a1, b1;
    cin >> a1 >> b1;
    ll sum = 1;
    sum *= a1;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
    for(int i=1; i<=n; i++) sum = sum * a[i] % mod;
    sort(b+1, b+1+n);
    // cout << sum << endl;
    cout << sum * ksm(b[1], mod-2) % mod << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}