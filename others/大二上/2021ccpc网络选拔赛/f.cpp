#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
char s[100100];
int n;
ll dp[10][100100];
const char *st = "nunhehheh";
int num[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        n = strlen(s);
        num[n] = (s[n-1] == 'a');
        for(int i=n-1; i>=1; i--) {
            if(s[i-1] == 'a') num[i] = num[i+1]*2+1;
            else num[i] = num[i+1];
            num[i] %= mod;
        }
        // for(int i=1; i<=n; i++)
        //     cout << num[i] << ' ';
        //     cout << endl;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=8; j++)
                dp[j][i] = 0;
        }
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            if(s[i-1] == 'n') dp[0][i]++;
            dp[0][i] += dp[0][i-1];
            dp[0][i] %= mod;
            for(int j=1; j<=8; j++) {
                if(s[i-1] == st[j]) {
                    dp[j][i] += dp[j-1][i-1];
                }
                if(j == 8) {
                    ans += dp[j][i] * num[i];
                    ans %= mod;
                }
                else dp[j][i] += dp[j][i-1];
                dp[j][i] %= mod;
            }
        }
        // for(int i=1; i<=n; i++) {
        //     for(int j=0; j<=8; j++)
        //         cout << dp[j][i] << ' ';
        //         cout << endl;
        // }
        cout << ans << endl;
    }
    return 0;
}
/*
1
nunhehheha

2
nunhehhehahaahahahahahahaahaahahahahha
nunhehhehhehhahaahahahaahaahahaaaahaa
*/