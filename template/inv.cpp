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


void exgcd(cint x_, cint y_, int&a_, int&b_) {
    if(!y_) {
        a_=1,b_=0;
        return;
    }
    exgcd(y_, x_%y_, b_, a_);
    b_ -= x_/y_ * a_;
}

ll ksm(ll m, int c) {
    ll ans = 1;
    while(c) {
        if(c&1) ans = (ans*m) % mod;
        c >>= 1;
        m = (m*m) % mod;
    }
    return ans;
}

ll fm(cint x, cint p) {
    return ksm(x,p-2);
}


int main() {
    int b, x, y, p = mod;
    cin >> b;
    exgcd(b, p, x, y);
    cout << ((x+p)%p==fm(b, p));
    return 0;
}