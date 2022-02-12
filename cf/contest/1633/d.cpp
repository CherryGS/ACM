// kaolvyixia yuchulide jielun
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
int dp[1001];
int b[1001];
ll c[1001];
ll val[1000100];

void init() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for(int i=1; i<=1000; i++) {
        for(int j=1; j<=i; j++) {
            if(i+i/j <= 1000) 
                dp[i+i/j] = min(dp[i+i/j], dp[i]+1);
        }
    }
}

void solve(cint T) {
    memset(val, 0, sizeof(val));
    val[0] = 1;
    int mx = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        b[i] = dp[b[i]];
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++) {
        for(int j=min(mx, k-b[i]); j>=0; j--) {
            if(val[j]) val[j+b[i]] = max(val[j+b[i]], val[j] + c[i]);
        }
        mx += b[i];
    }
    for(int i=0; i<=mx; i++)
        ans = max(ans, val[i]);
    cout << ans - 1 << endl;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    init();
    for(int _T=1; _T<=T_; _T++)
        solve(_T);
    return 0;
}