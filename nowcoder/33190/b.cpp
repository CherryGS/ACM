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

ll n, m;
ll a[100100];
ll b[100100];

bool check(int x) {
    for(int i=1; i<=n; i++) { b[i] = a[i] + 1ll * x * i; }
    sort(b+1, b+1+n);
    int ans = 0;
    ll mm = m;
    for(int i=1; i<=n; i++) {
        ll t = b[i];
        if(t > mm) { break; }
        mm -= t;
        ++ans;
    }
    // if(x == 1) { cout << ans << ' ' << m << endl; }
    return ans >= x;
}

void solve(cint T) {
    n = 0;
    cin >> n >> m;
    if(n == 0) { return; }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int l = 0, r = n, mid;
    while(l < r) {
        mid = l + ((r-l+1)>>1);
        if(check(mid)) { l = mid; }
        else { r = mid - 1; }
    }
    cout << l << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=10000;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}