#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
ll a[100100];
ll dp[502][100100];


int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        int ans = 1;
        cin >> n;
        for(int i=1; i<=n; i++) for(int j=1; j<=500; j++) dp[j][i] = -1;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=n-1; i>=1; i--) a[i] += a[i+1];
        for(int i=n; i>=1; i--) {
            dp[1][i] = max(dp[1][i], a[i]-a[i+1]);
            for(int j=2; j<=500; j++) {
                if(dp[j-1][i] != -1) {
                    if(i-j > 0 && a[i-j]-a[i] < dp[j-1][i]) {
                        dp[j][i-j] = max(dp[j][i-j], a[i-j]-a[i]);
                        ans = max(ans, j);
                    }
                    dp[j-1][i-1] = max(dp[j-1][i], dp[j-1][i-1]);
                }
            }
            dp[1][i-1] = max(dp[1][i-1], dp[1][i]);
        }
        for(int i=1; i<=n; i++) a[i] = 0;
        cout << ans << endl;
    }
    return 0;
}
/*
1
5
1 1 2 2 3
*/