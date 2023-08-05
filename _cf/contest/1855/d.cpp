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
int a[100100];
ll b[100100];
bitset<200001> v;

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> a[i]; b[i] = a[i] + b[i-1]; }
    v[1] = 1;
    ll mx = 1;
    ll ans = 0;
    for(int i=1; i<=n && i<=mx; i++) {
        v |= v << a[i];
        mx += a[i];
        if(v[i]) {
            v[i] = 0;
            ans = max(ans, b[min(n,i)] - i + 1);
        }
    }
    for(int i=n+1; i<=n*2; i++) if(v[i]) {
        ans = max(ans, b[min(n,i)] - i + 1);
    }
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}
