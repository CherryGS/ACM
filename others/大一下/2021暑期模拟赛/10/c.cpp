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
ll a[303];
ll dp[303][303];
ll pre[303][303];

void init() {
    for(int i=1; i<=n; i++) pre[i][i] = a[i];
    for(int j=1; j<=n; j++)
        for(int i=1; i<=n; i++) {
            if(j+i > n) break;
            pre[i][j+i] = (pre[i][j+i-1]*a[j+i]) % 1000003;
        }
}

ll cacu1(cint i, cint j, cint k) {
    return pow(abs(pre[i][i+j]-pre[i+j+1][i+j+k]), 2);
}

ll cacu2(cint i, cint j, cint k) {
    return pow(abs(pre[i-k][i-1]-pre[i][i+j]), 2);
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    init();
    for(int j=0; j<n; j++) {
        for(int i=1; i+j<=n; i++) {
            for(int k=1; i+j+k<=n; k++) {
                dp[i][i+j+k] = max(dp[i][i+j+k], dp[i][i+j]+dp[i+j+1][i+j+k]+cacu1(i, j, k));
            }
            for(int k=1; i-k>0; k++) {
                dp[i-k][i+j] = max(dp[i-k][i+j], dp[i][i+j]+dp[i-k][i-1]+cacu2(i, j, k));
            }
        }
    }
    cout << dp[1][n];
    return 0;
}