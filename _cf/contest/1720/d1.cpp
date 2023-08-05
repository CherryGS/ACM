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
int a[300001];

void solve(cint T) {
    cin >> n;
    int ans = 1;
    for(int i=0; i<n; i++) { cin >> a[i]; }
    for(int i=0; i<n; i+=256) {
        int r = min(n-1, i+256-1);
        int s[256];
        for(int j=0; j<256; j++) { s[j] = 1; }
        for(int j=i; j<=r; j++) {
            for(int k=i; k<j; k++) {
                // cout << j << ' ' << k << ' ' << a[j] << ' ' << a[k] << ' ' << (a[k]^j) << ' ' << (a[j]^k) << endl;
                if((a[k]^j) < (a[j]^k)) { s[j-i] = max(s[j-i], s[k-i]+1); ans = max(ans, s[j-i]); }
            }
        }
        // for(int j=0; j<n; j++) { cout << s[i] << ' '; }
        // cout << endl;
    }
    // for(int i=1; i<=n; i++) { cout << a[i] << ' '; }
    // cout << endl;
    cout << ans << '\n';
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