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
#define ifor(s, e) for(int i=s;i<=e;i+=1)
#define jfor(s, e) for(int j=s;j<=e;j+=1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int add(ll x, const int &y) { x += y; return x >= mod ? x - mod : x; }
int sub(ll x, const int &y) { x -= y; return x >= 0 ? x : x + mod; }
int mul(ll x, const int &y) { x *= y; return x >= mod ? x % mod : x; }

int n, k;
char c[300300];
int dp[300300][102];
int siz[5];

void solve(cint T) {
    cin >> n >> k;
    cin >> c;
    dp[0][0] = 1;
    ifor(1, n) {
        jfor(0, k) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            dp[i][j+1] = (dp[i][j+1] + 1ll * dp[i-1][j] * (i-siz[c[i-1]-'A']-1) % mod) % mod;
        }
        ++siz[c[i-1]-'A'];
    }
    // ifor(1, n) {
    //     jfor(0, k) { cout << dp[i][j] << ' '; }
    //     cout << endl;
    // }
    ll ans = 0;
    ifor(0, k) { ans = (ans + dp[n][i]) % mod; }
    cout << ans << '\n';
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    //std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { solve(_T); }
    return 0;
}
