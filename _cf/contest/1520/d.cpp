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
int a[200200];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i], a[i] -= i;
        sort(a+1, a+1+n);
        ll ans = 0;
        ll sum = 0;
        for(int i=1; i<=n+1; i++) {
            if(a[i] != a[i-1] || i == n+1) {
                ans += sum*(sum-1)/2;
                sum = 0;
            }
            ++sum;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
7
1 2 3 4 5 5 6
*/