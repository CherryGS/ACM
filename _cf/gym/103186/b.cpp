#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, a, b, c;
ll dp[5050][5050];
struct node {
    int x, y, z;
    bool operator < (const node&a) const {
        return y-x > a.y - a.x;
    }
    void init() {
        cin >> x >> y >> z;
    }
} r[5050];

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a >> b >> c;
    for(int i=1; i<=n; i++) r[i].init();
    sort(r+1, r+1+n);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<min(c+1, i); j++) {
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + r[i].z);
            int ss = i-j-1;
            if(ss < b) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + r[i].y);
            }
            else {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + r[i].x);
            }
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}