#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n;
ll a[2020];
ll dp[2020][2020];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    for(int i=1; i<=n-1; i++)
        for(int j=n-i; j>=1; j--) {
            dp[j][j+i] = min(dp[j][j+i-1], dp[j+1][j+i]) + a[j+i] - a[j];
        }
    cout << dp[1][n] << endl;
    return 0;
}