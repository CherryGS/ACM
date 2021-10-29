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

int t, n, m;
int r[101], b[101];

int main() {
    cin >> t;
    while(t--) {
        int ans=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> r[i], r[i] += r[i-1];
        cin >> m;
        for(int i=1; i<=m; i++) cin >> b[i], b[i] += b[i-1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                ans = max(ans, r[i] + b[j]);
        cout << ans << endl;
    }
    return 0;
}