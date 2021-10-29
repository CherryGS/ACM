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

string n;
int dp[3];

int main() {
    int sum = 0;
    cin >> n;
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=0; i<n.length(); i++) {
        int k = (n[i]-'0') % 3;
        if(k)dp[k]=1;
        sum += k;
        for(int j=0; j<3; j++) dp[(j+k)%3] = min(dp[(j+k)%3], dp[j]+1);
    }
    if(n.length() != dp[sum%3]) cout << dp[sum%3];
    else cout << -1;
    return 0;
}