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

int t;
int n, l, r;
int le[2002000], ri[2002000];

int main() {
    cin >> t;
    while(t--) {
        int mx = 0;
        cin >> n >> l >> r;
        int s;
        for(int i=1; i<=n; i++) le[i] = ri[i] = 0;
        for(int i=1; i<=n; i++) {
            cin >> s;
            if(i <= l) ++le[s];
            else ++ri[s];
            mx = max(mx, s);
        }
        for(int i=1; i<=mx; i++) {
            int s = min(le[i], ri[i]);
            le[i] -= s; ri[i] -= s;
            l -= s; r -= s;
        }
        int ans = 0;
        for(int i=1; i<=mx; i++) {
            while(r > l && ri[i] >= 2) {
                ++ans;
                ri[i] -= 2;
                r -= 2;
            }
            while(l > r && le[i] >= 2) {
                ++ans;
                le[i] -= 2;
                l -= 2;
            }
        }
        cout << ans + max(l, r) << endl;
    }
    return 0;
}