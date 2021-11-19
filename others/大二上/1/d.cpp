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

int n, K, P;
int dp[2002][11];
int w[2002], v[2002], p[2002];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) {
        cin >> n >> K >> P;
        int ans = 0;
        for(int i=1; i<=n; i++) cin >> w[i] >> v[i] >> p[i];
        for(int i=1; i<=n; i++) { 
            for(int j=K-w[i]; j>=0; j--) {
                for(int k=P-p[i]; k>=0; k--) {
                    if(dp[j][k] || (j==0&&k==0)) {
                        dp[j+w[i]][k+p[i]] = max(dp[j+w[i]][k+p[i]], dp[j][k]+v[i]);
                        ans = max(ans, dp[j+w[i]][k+p[i]]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}