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

int n, k;
int l[11], r[11];
ll sum[11];
ll dp[200200];

int main() {
    cin >> n >> k;
    for(int i=1; i<=k; i++) cin >> l[i] >> r[i];
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(l[j] < i) {
                sum[j] += dp[i-l[j]];
                if(r[j] < i-1) sum[j] -= dp[i-r[j]-1];
                if(sum[j] < 0) sum[j] += mod;
                else sum[j] %= mod;
                dp[i] += sum[j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n];
    return 0;
}