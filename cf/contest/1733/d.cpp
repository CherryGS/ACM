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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, x, y;
char s[5005], t[5005];
bool a[5005];
ll dp[5001][5001][2];

bool solve(cint T) {
    cin >> n >> x >> y;
    cin >> s;
    cin >> t;
    int sum = 0;
    for(int i=1; i<=n; i++) { a[i] = abs(s[i-1]-t[i-1]); sum += a[i]; }
    if(sum % 2 == 1) { cout << -1 << '\n'; return true; } 
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j][0] = dp[i][j][1] = inf_ll/2;
        }
    }
    dp[0][0][0] = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n-i; j++) {
            if(a[i+1] == 1) {   
                if(dp[i][j][0] < inf_ll/2) {
                    dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][0]);
                    if(j > 0) {
                        dp[i+1][j-1][0] = min(dp[i+1][j-1][0], dp[i][j][0] + y);
                    }
                    dp[i+1][j+1][0] = min(dp[i+1][j+1][0], dp[i][j][0] + y);
                    if(i+2 <= n && a[i+2] == 1) {
                        dp[i+2][j][0] = min(dp[i+2][j][0], dp[i][j][0] + x);
                    }
                }
                if(dp[i][j][1] < inf_ll/2) {
                    dp[i+1][j+1][1] = min(dp[i+1][j+1][1], dp[i][j][1]);
                    if(j > 0) {
                        dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + y);
                    }
                    dp[i+1][j+2][0] = min(dp[i+1][j+2][0], dp[i][j][1] + y);
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + x);
                    if(i+2 <= n && a[i+2] == 1) {
                        dp[i+2][j+1][0] = min(dp[i+2][j+1][0], dp[i][j][1] + x);
                    }
                }
            }
            else {
                dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]);
                dp[i+1][j+1][0] = min(dp[i+1][j+1][0], dp[i][j][1]);
                dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][1] + x);
            }
        }
    }
    // cout << dp[5][0][1] << '\n';
    cout << dp[n][0][0] << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}