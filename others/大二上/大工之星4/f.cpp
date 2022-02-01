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
int val[101];
int sco[101];
bool li[101];
int dp[100010];

void solve(cint T) {
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> val[i] >> sco[i] >> li[i];
    int ans = 0;
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        if(li[i]) {
            for(int j=0; j<=m; j++)
                if(j - val[i] >= 0 && dp[j-val[i]]) {
                    dp[j] = max(dp[j], dp[j-val[i]] + sco[i]);
                }
        }
        else {
            for(int j=m; j>=0; j--)
                if(j - val[i] >= 0 && dp[j-val[i]]) {
                    dp[j] = max(dp[j], dp[j-val[i]] + sco[i]);
                }
        }
    }
    for(int i=m; i>=0; i--) ans = max(ans, dp[i]);
    cout << ans-1 << endl;
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