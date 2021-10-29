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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
long double pi = acos(-1);
long double w, d;

int main() {
    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> w >> d;
        long double r = sqrt(w*w+d*d);
        w = min(w, d);
        for(int i=0; i<=3; i++) {
            if(w*i < pi) {
                int st = (pi-w*i)/r;
                ans = max(ans, 2*i+3*st);
            }
            if(r*i < pi) {
                int st = (pi-r*i)/w;
                ans = max(ans, 2*st+3*i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}