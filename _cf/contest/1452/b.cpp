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
ll n;
ll a[100100];

ll gcd(cint x, cint y) {
    return y==0? x: gcd(y, x%y);
}

int main() {
    cin >> t;
    while(t--) {
        ll mx=0;
        ll sum=0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        if(sum <= mx*(n-1)) cout << mx*(n-1)-sum << endl;
        else if(!(sum%(n-1))) cout << 0 << endl;
        else cout << (n-1) - (sum%(n-1)) << endl;
    }
    return 0;
}