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

int t;
int n;
int a[51];
bool dp[101];

int main() {
    cin >> t;
    while(t--) {
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int ans=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++)
            for(int j=i-1; j; j--)
                if(!dp[a[i]-a[j]]) {
                    dp[a[i]-a[j]] = 1;
                    ++ans;
                }
        cout << ans << endl;
    }
    return 0;
}