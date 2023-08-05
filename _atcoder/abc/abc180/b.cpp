#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n;
ll a = 0, b = 0, c = 0;

int main() {
    cin >> n;
    ll d;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        if(d < 0) d = -d;
        a += d;
        b += (d*d);
        c = max(c, d);
    }
    printf("%lld\n%.12f\n%lld", a, sqrt(b), c);
    return 0;
}