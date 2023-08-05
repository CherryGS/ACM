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

int n, k;
int a[100003];

void solve(cint T) {
    cin >> n >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    int ans = inf_int;
    for(int i=1; i<=100000; i++) {
        int mx = 0, mn = inf_int;
        for(int j=1; j<=n; j++) {
            int t;
            if(i == 0) { t = a[j] + 1; }
            else { t = a[j] / i; }
            t = min(k, t);
            t = max(1, t);
            mx = max(mx, a[j]/t);
            mn = min(mn, a[j]/t);
            // cout << a[j] / t << endl;
        }
        ans = min(ans, mx-mn);
    }
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