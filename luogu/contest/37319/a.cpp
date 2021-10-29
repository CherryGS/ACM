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

int t;
ll a, b, c, d, e;

bool check(cint x) {
    if(x < e) return 0;
    if(!((x-e)%b)) return 1;
    return 0;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        e = a*c;
        int ans=0;
        for(int i=1; i<=sqrt(d); i++)
            if(!(d%i)) {
                ans += check(i);
                if(i != d/i)ans += check(d/i);
            }
        cout << ans << endl;
    }
    return 0;
}