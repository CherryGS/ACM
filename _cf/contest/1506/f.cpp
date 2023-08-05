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
struct stu{
    int x, y;
    bool operator < (const stu a) const {
        return x < a.x;
    }
    int dt() {
        return x - y;
    }
}a[200200];

int main() {
    cin >> t;
    a[0].x = 1, a[0].y = 1;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i].x;
        for(int i=1; i<=n; i++) cin >> a[i].y;
        sort(a+1, a+1+n);
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int a1 = a[i].dt(), a2 = a[i-1].dt();
            if(a1 == a2 && !(a1&1)) ans += a[i].x - a[i-1].x;
            else {
                ans += (a1/2-a2/2);
            }
        }
        cout << ans << endl;
    }
    return 0;
}