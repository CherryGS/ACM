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

ll ans=1;

int main() {
    int t;
    cin >> t;
    ll a;
    while(t--) {
        cin >> a;
        ans=1;
        while(ans < a) ans <<= 1;
        cout << ans << endl;
    }
    return 0;
}