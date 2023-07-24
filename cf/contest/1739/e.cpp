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

int n;
char s[2][200200];
int dp[2][2][200200];

bool solve(cint T) {
    cin >> n;
    cin >> s[0];
    cin >> s[1];
    memset(dp, 0x7f, sizeof dp);
    dp[0][0][0] = 0;
    int sum = 0;
    int ans = inf_int;
    for(int i=0; i<n; ++i) {
        sum = sum + s[0][i] - '0' + s[1][i] - '0';
        for(int jj=0; jj<=1; ++jj) {
            for(int kk=0; kk<=1; ++kk) {
                int j = kk, k = (jj+kk)%2;
                if(dp[j][k][i] <= hf_int) {
                    int l = i;
                    if(j != k) {
                        if(i+1 < n && s[j][i+1] == '1') {
                            dp[j][j][i+1] = min(dp[j][j][i+1], dp[j][k][i]);
                            continue;
                        }
                        if(i+2 < n && s[j][i+2] == '1') {
                            dp[j][j][i+2] = min(dp[j][j][i+2], dp[j][k][i]);
                            continue;
                        }
                        l = i+3;
                    }
                    while(l < n-1 && s[j][l+1] == '0' && s[j^1][l] == '0') { ++l; }
                    if(l >= n-1) { ans = min(ans, dp[j][k][i]); }
                    else if(s[j][l+1] == '1' && s[j^1][l] == '1') {
                        dp[j][j][l+1] = min(dp[j][j][l+1], dp[j][k][i] + 1);
                        dp[j^1][j][l] = min(dp[j^1][j][l], dp[j][k][i] + 1);
                    }
                    else if(s[j][l+1] == '1') { dp[j][j][l+1] = min(dp[j][j][l+1], dp[j][k][i]); }
                    else if(s[j^1][l] == '1') { dp[j^1][j][l] = min(dp[j^1][j][l], dp[j][k][i]); }
                    // if(j == 1 && k == 0 && i == 8) { cout << l << endl;}
                    cout << ans << ' ' << j << ' ' << k << ' ' << i << endl;
                }
                // if(i == n-1) { ans = min(ans, dp[j][k][i]); }
            }
        }
    }
    /*
    10
    0101001010
    1010100110
    */
    cout << dp[0][0][8] << endl;
    cout << sum << ' ' << ans << endl;
    cout << sum-ans << '\n';
    return true;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_=1;
    // std::cin >> T_;
    for(int _T=1; _T<=T_; _T++) { if(solve(_T) == 0) { break; } }
    return 0;
}