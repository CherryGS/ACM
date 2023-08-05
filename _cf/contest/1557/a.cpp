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

int t, n;
int a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        ll sum = 0;
        for(int i=1; i<=n; i++) sum += a[i];
        double ans;
        bool flag = 0;
        ll pre = 0;
        for(int i=1; i<=n; i++) {
            pre += a[i];
            sum -= a[i];
            if(flag) ans = max(ans, (double)(pre)/i+(double)(sum)/(n-i));
            else ans = (double)(pre)/i+(double)(sum)/(n-i), flag = 1;
        }
        printf("%.9f\n", ans);
    }
    return 0;
}