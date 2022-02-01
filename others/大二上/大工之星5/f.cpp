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

int n, m;

int p[100100], a[100100];

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> p[i] >> a[i];
    bool flag = 1;
    int ans = a[1] + p[1] - 1;
    for(int i=2; i<=m; i++) {
        if(a[i] - a[i-1] > p[i] - p[i-1]) { flag = 0; break; }
        ans = max(ans, (p[i]-p[i-1]+a[i]+a[i-1])/2);
    }
    ans = max(ans, a[m]-p[m]+n);
    if(flag) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
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