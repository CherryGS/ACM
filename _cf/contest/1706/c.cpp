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

// 01001010
int n;
ll h[100100];
ll s[100100];

ll c(int x) {
    return max(0ll, max(h[x-1], h[x+1])-h[x]+1);
}

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) { cin >> h[i]; }
    for(int i=2; i<n; i+=2) { s[i] = s[i-2] + c(i); }
    if(n & 1) {
        cout << s[n-1] << '\n';
        return;
    }
    ll ans = inf_ll, sum = 0;
    for(int i=n-1; i>=2; i-=2) {
        ans = min(ans, sum + s[i-1]);
        sum += c(i);
    }
    // cout << " --- " << sum << endl;
    ans = min(ans, sum);
    cout << ans << '\n';
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