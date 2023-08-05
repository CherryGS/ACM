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

int n, k;
int m;

ll a[200200];

bool solve(cint T) {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=30; i>=0; i--) {
        ll sum = 0;
        sort(a+1, a+1+n, [](cint a, cint b) { return a > b; } );
        for(int j=1; j<=k; j++) { sum += max(0ll, (1ll<<i) - (a[j] % (1ll<<(i+1)))); }
        if(sum <= m) {
            m -= sum;
            for(int j=1; j<=k; j++) { a[j] += max(0ll, (1ll<<i) - (a[j] % (1ll<<(i+1)))); }
        }
        else { for(int j=1; j<=n; j++) { if((a[j]>>i)&1) { a[j] ^= (1ll<<i); } } }
    }
    ll ans = (1ll<<31) - 1;
    for(int i=1; i<=k; i++) { ans &= a[i]; }
    cout << ans << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}