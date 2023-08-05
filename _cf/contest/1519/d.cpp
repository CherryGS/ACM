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

ll sum[5001][2];
ll dp[5001][2];
ll a[5001], b[5001];
int n;
ll pre_ans;
ll mx;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) mx += a[i]*b[i];

    for(int i=1; i<=n; i++) {
        if(i == 1) for(int j=1; j<=n; j++) dp[j][1] = sum[j][1] = a[j]*b[j];
        else if(i & 1) {
            int r = (i-1)/2;
            for(int j=r+1; j+r<=n; j++) 
                sum[j][1] = sum[j][1] + a[j-r]*b[j-r] + a[j+r]*b[j+r];
        } 
        else {
            int r = i/2-1;
            for(int j=r+1; j+1+r<=n; j++) 
                sum[j][0] = sum[j][0] + a[j-r]*b[j-r] + a[j+1+r]*b[j+1+r];
        }

        if((i&1) && (i != 1)) {
            int r = (i-1)/2;
            for(int j=r+1; j+r<=n; j++) {
                dp[j][1] = dp[j][1] + a[j-r]*b[j+r] + a[j+r]*b[j-r];
                pre_ans = max(pre_ans, dp[j][1] - sum[j][1]);
            }
        }
        if(!(i&1)) {
            int r = i/2-1;
            for(int j=r+1; j+1+r<=n; j++) {
                dp[j][0] = dp[j][0] + a[j-r]*b[j+1+r] + a[j+1+r]*b[j-r];
                pre_ans = max(pre_ans, dp[j][0] - sum[j][0]);
            }
        }
    }

    cout << mx + pre_ans << endl;
    return 0;
}