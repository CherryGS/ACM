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
bool mp[101];

int main() {
    cin >> t;
    while(t--) {
        memset(mp, 0, sizeof mp);
        cin >> n >> m;
        int a, ans=0;
        for(int i=1; i<=n; i++) {
            cin >> a;
            mp[a] = 1;
        }
        for(int i=1; i<=m; i++) {
            cin >> a;
            if(mp[a]) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}