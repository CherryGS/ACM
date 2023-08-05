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
ll a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        ll mn = (ll)inf_int*3;
        ll tmp = (ll)inf_int*4;
        int s2 = 0;
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) {
            if(a[i] <= 0) {
                ++s2;
                if(i != 1) mn = min(mn, a[i]-a[i-1]);
            }
            if(a[i] > 0) {
                tmp = a[i];
                break;
            }
        }
        if(!s2) cout << 1 << endl;
        else cout << s2+ (mn >= tmp) << endl;
    }
    return 0;
}
/*
1
5
-1 -2 -3 -4 -5
*/