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
ull a, b, c, d, k;

int main() {
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> a >> b >> c >> d;
        int r = 0;
        for(ull i=1; i<=d/(c-b); i++) {
            if((a+(b*i))%d && (a+(c*i))/d == (a+(b*i))/d) {
                ++ ans;
                if(i-1 != r) {
                    cout << r << ' ' << i << endl;
                }
                r = i;
            }
        }
        cout << ans << "---" << endl;
    }
    return 0;
}
/*
1
50050555 99999996 99999999 100000000
*/