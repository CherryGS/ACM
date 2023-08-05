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
int a[5005];
int dp[5005][(1<<13)+1];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++){ cin >> a[i]; }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=(1<<13); j++) {
            dp[i][j] = hf_int;
        }
    }
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=(1<<13); j++) {
            if(dp[i][j] < hf_int) {
                int t1 = a[i+1] ^ j;
                dp[i+1][t1] = min(dp[i+1][t1], dp[i][j] + (t1!=0));
                dp[i+1][0] = min(dp[i+1][0], dp[i][j] + (t1!=0));
            }
        }
    }
    int ans = hf_int;
    for(int i=0; i<=5000; i++) { ans = min(ans, dp[n][i]); }
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