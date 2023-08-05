#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll dp[11][2][2];
ll n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        int cnt = 0;
        while(n) {
            int r = n%10;
            n /= 10;
            ++cnt;
            for(int i=0; i<=9; i++) {
                for(int j=0; j<=9; j++) {
                    if((i+j)%10 == r) {
                        // cout << i << ' ' << j << endl;
                        dp[cnt][(i+j)>9][0] += dp[cnt-1][0][0];
                        dp[cnt][(i+j)>9][1] += dp[cnt-1][1][0];
                    }
                    else if((i+j+1)%10 == r) {
                        dp[cnt][(i+j+1)>9][0] += dp[cnt-1][0][1];
                        dp[cnt][(i+j+1)>9][1] += dp[cnt-1][1][1];
                    }
                }
            }
        }
        cout << dp[cnt][0][0] - 2 << endl;
    }
    return 0;
}