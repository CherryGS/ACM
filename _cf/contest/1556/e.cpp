#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, q;
int a[100100], b[100100];
ll dp[100100][20][2]; // 0 mn 1 mx
ll sum[100100];
int to[100100];

void init() {
    for(int i=2; i<=100000; i++) {
        to[i] = to[i/2]+1;
    }
}

int main() {
    init();
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) sum[i] += sum[i-1] + a[i]-b[i];
    // for(int i=1; i<=n; i++)
    //     cout << sum[i] << ' ';
    //     cout << endl;
    for(int i=1; i<=n; i++) dp[i][0][0] = dp[i][0][1] = sum[i];
    for(int j=1; j<=19; j++) {
        for(int i=1; i<=n; i++) {
            int r = min(n, i+(1<<(j-1)));
            dp[i][j][0] = min(dp[i][j-1][0], dp[r][j-1][0]);
            dp[i][j][1] = max(dp[i][j-1][1], dp[r][j-1][1]);
        }
    }
    int l, r;
    for(int i=1; i<=q; i++) {
        cin >> l >> r;
        if(sum[r] - sum[l-1]) {
            cout << -1 << endl;
            continue;
        }
        int st = to[r-l+1];
        ll mn = min(dp[l][st][0], dp[r-(1<<st)+1][st][0]) - sum[l-1];
        ll mx = max(dp[l][st][1], dp[r-(1<<st)+1][st][1]) - sum[l-1];
        cout << (mx <= 0 ? abs(mn) : -1) << endl;
    }
    return 0;
}