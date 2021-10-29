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

string a;
int n;
char t[3] = {'1', '1', '0'};
ll l = 0;

int main() {
    bool flag=0;
    cin >> n >> a;
    if(a == "1" ) {
        cout << (ll)(2*1e10) << endl;
        return 0;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<n; j++) {
            if(t[(i+j)%3] != a[j]) break;
            if(j == n-1) flag=1;
        }
        if(flag) {
            ll ans = 1e10 - (n+i+2)/3 + 1;
            cout << ans << endl;
            return 0;
        }
    }
    cout << 0 << endl;


    return 0;
}