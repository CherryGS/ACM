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

const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, mod;

ll dp[55][2505];

ll sol(cint x) {
    ll pre = 0;
    
    return (pre + (ll)x*sol(x-1)) % mod;
}

int main() {
    cin >> n >> mod;
    init();
    int mx = 0;
    dp[1][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=mx; j>=0; j--) {
            for(int k=0; k<=i; k++) {
                dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]) % mod;
                mx = max(mx, j+k);
            }
        }
    }

    cout << sol(n) << endl;

    return 0;
}