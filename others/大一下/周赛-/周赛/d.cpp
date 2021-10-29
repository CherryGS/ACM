#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, m, l;
int a[100100];
ll dp[100100];
int q1[100100], q2[100100], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m >> l;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) dp[i] = -1;
        dp[1] = m;
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=l && i-j >=1; j++)
                dp[i] = max(dp[i], dp[i-j] - max(a[i]-a[i-j], 0));
        }
        cout << dp[n] << endl;
    }
    return 0;
}