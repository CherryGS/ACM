#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll dp[5005][5005];
ll sum[5005];
ll to[5005];

void init() {
    to[0] = 1;
    for(int i=1; i<=5000; i++)
        to[i] = to[i-1] * i % mod;
}

int main() {
    // freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tmp;
    cin >> n;
    init();
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        sum[tmp]++;
    }
    dp[0][0] = 1;
    ll s = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum[i]; j++) {
            for(int k=0; k<=s; k++) {
                if(j+k >= sum[i]-j+s-k && k >= s-k) {
                    // cout << i << ' ' << j << ' ' << k << endl;
                    dp[i][j+k] += dp[i-1][k] * to[sum[i]];
                    dp[i][j+k] %= mod;
                }
            }
        }
        s += sum[i];
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++)
    //         cout << dp[i][j] << ' ';
    //         cout << endl;
    // }
    cout << dp[n][n/2] << endl;
    return 0;
}