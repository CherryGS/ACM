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

ll n, a, b, x, y, z;

void solve(cint T) {
    cin >> n >> a >> b >> x >> y >> z;
    y = min(y, x*a);
    z = min(z, x*b);
    if(a > b) {
        swap(a, b);
        swap(y, z);
    }
    ll l = n / (a*b);
    ll ans = 0;
    ll pre = inf_ll;
    n %= a*b;
    if(l) { n += a*b; ans = min(z*a, y*b) * (l-1); }
    for(ll i=0; b*i<=n; i++) { pre = min(pre, z*i + y*((n-b*i)/a) + x*((n-b*i)%a)); }
    cout << ans + pre << endl;
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