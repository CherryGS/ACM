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
int l[200200], r[200200], w[200200];
int a[200200];
int flag[200200];
ll to[200200];

void init() {
    to[0] = 1;
    for(int i=1; i<=200000; i++)
        to[i] = to[i-1] * 2 % mod1;
}

ll cacu(int x) {
    int s1 = 0;
    for(int i=1; i<=n; i++) flag[i] = 0;
    for(int i=1; i<=m; i++)
        if(!(w[i]&(1<<x))) {
            ++flag[l[i]];
            --flag[r[i]+1];
        }
    int s = 0;
    for(int i=1; i<=n; i++) {
        s += flag[i];
        if(s > 0) ++ s1;
    }
    return to[s1] * to[n-s1-1] % mod1 * (1<<x) % mod1;
}

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) a[i] = 0;
    for(int i=1; i<=m; i++)
        cin >> l[i] >> r[i] >> w[i];
    ll ans = 0;
    for(int i=0; i<30; i++) {
        ans += cacu(i);
        ans %= mod1;
    }
    cout << ans << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    init();
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}