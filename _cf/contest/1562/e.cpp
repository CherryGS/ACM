#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
char s[5050];
ll dp[5050];
int pre[5050][5050];

void debug() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << pre[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        ll ans = 0;
        for(int i=1; i<n; i++) {
            int r = 1;
            for(int j=1; j+i<=n; j++) {
                if(s[j-1] != s[i+j-1]) {
                    while(r <= j) {
                        pre[r][r+i] = j;
                        ++r;
                    }
                }
            }
        }
        // debug();
        for(int i=1; i<=n; i++) {
            dp[i] = 0;
            for(int j=i-1; j >= 0; j--) {
                if(j == 0 || s[i-1] > s[j-1]) dp[i] = max(dp[i], dp[j]+n-i+1);
                else if(s[i-1] == s[j-1]) {
                    int r = pre[j][i];
                    if(r && s[r-1] < s[r-1+i-j]) dp[i] = max(dp[i], dp[j]+n-(r+i-j)+1);
                }
            }
            ans = max(ans, dp[i]);
            // cout << i << ' ' << dp[i] << endl;
        }
        cout << ans << endl;
    }
    return 0;
}