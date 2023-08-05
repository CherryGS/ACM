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
int n, k;
int a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        int now = 0, tmp = -1, ans = 1;
        if(k)
        for(int i=1; i<=n; i++) {
            if(a[i] == now) ++now;
            else if(a[i] > now) {
                a[++n] = (now + a[n]+1)/2;
                tmp = 0;
                break;
            }
        }
        sort(a+1, a+1+n);
        for(int i=2; i<=n; i++) {
            if(a[i] != a[i-1]) ++ ans;
        }
        if(tmp) ans += k;
        cout << ans << endl;
    }
    return 0;
}