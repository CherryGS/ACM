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
int n, u, v;
int a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> u >> v;
        for(int i=1; i<=n; i++) cin >> a[i];
        int ans = inf_int;
        for(int i=1; i<=n; i++) {
            //between row
            if(i != n)
            if(a[i+1] != a[i]) {
                ans = min(ans, u);
            } else {
                ans = min(ans, u+v);
            }

            // between column
            if(i != n)
            if(a[i+1] != a[i]) {
                if(abs(a[i+1] - a[i]) >= 2) ans = 0;
                else {
                    ans = min(ans, v);
                }
            } else ans = min(ans, 2*v);
        }
        cout << ans << endl;
    }
    return 0;
}