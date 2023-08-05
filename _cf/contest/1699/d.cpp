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
int dp[5005];
int sum[5005];
bool ok[5005][5005];

void solve(cint T) {
    cin >> n;
    for(int i=1; i<=n; i++) {
        dp[i] = 0;
        for(int j=1; j<=n; j++) {
            ok[i][j] = false;
        }
    }
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    for(int i=1; i<=n; i++) {
        int mx = 0;
        memset(sum, 0, sizeof sum);
        for(int j=0; j<=n; j++) {
            if(j < i) { ok[i][j] = true; continue; }
            ++sum[a[j]];
            mx = max(mx, sum[a[j]]);
            if((j-i+1) % 2 == 0 && mx * 2 - (j-i+1) <= 0) { 
                ok[i][j] = true; 
            }
        }
    }

    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << ok[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for(int i=1; i<=n; i++) {
        dp[i] = ok[1][i-1];
        for(int j=i-1; j>=1; j--) {
            if(a[i] == a[j] && ok[j+1][i-1] == true && dp[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for(int i=1; i<=n; i++) { cout << dp[i] << ' '; }
    // cout << endl;

    int ans = 0;

    for(int i=1; i<=n; i++) {
        if(i+1 > n || ok[i+1][n] == true) {
            ans = max(ans, dp[i]);
        }
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