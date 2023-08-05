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

int n;
ll a[2002];
ll dp[2002];

int main() {
    cin >> n;
    int mx = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
        for(int j=mx; j>=0; j--)
            if(dp[j] >= 0 || j == 0) {
                if(dp[j] >= - a[i]) {
                    dp[j+1] = max(dp[j+1], dp[j]+a[i]);
                    mx = max(mx, j+1);
                }
            }
    cout << mx << endl;
    return 0;
}