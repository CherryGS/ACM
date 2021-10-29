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

ll dp[2];

int main() {
    dp[0] = 1;
    int n;
    bool st=0;
    ll sum = 1;
    cin >> n;
    for(int i=1; i<=n; i++, st^=1) {
        dp[st^1] = (dp[st] + (sum<<1)) % mod;
        sum = (sum+dp[st^1]) % mod;
    }
    cout << dp[st] << endl;
    return 0;
}