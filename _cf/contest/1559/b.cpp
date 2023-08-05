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
int dp[101][2]; // 0 b ; 1 r
char s[101];
int to[101][2];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = dp[0][1] = 0;
        for(int i=0; i<n; i++) {
            if(s[i] != 'R') {
                if(dp[i+1][0] > dp[i][1]) {
                    dp[i+1][0] = dp[i][1];
                    to[i+1][0] = 1;
                }
                if(dp[i+1][0] > dp[i][0] + 1) {
                    dp[i+1][0] = dp[i][0] + 1;
                    to[i+1][0] = 0;
                }
            }
            if(s[i] != 'B') {
                if(dp[i+1][1] > dp[i][1]+1) {
                    dp[i+1][1] = dp[i][1]+1;
                    to[i+1][1] = 1;
                }
                if(dp[i+1][1] > dp[i][0]) {
                    dp[i+1][1] = dp[i][0];
                    to[i+1][1] = 0;
                }
            }
        }
        int r;
        vector<int> ans;
        if(dp[n][0] > dp[n][1]) r = 1;
        else r = 0;
        for(int i=n; i; i--) {
            ans.push_back(r);
            r = to[i][r];
        }
        for(int i=ans.size()-1; i>=0; i--) {
            if(ans[i] == 1) cout << "R";
            else cout << "B";
        }
        cout << endl;
    }
    return 0;
}