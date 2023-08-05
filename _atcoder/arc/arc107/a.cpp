#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ll a,b,c;
const int mod = 998244353;

ll sol(ll s) {
    s %= mod;
    return (s*(s+1)/2) % mod;
}

int main() {
    cin >> a >> b >> c;
    cout << ((sol(a) * sol(b)) % mod * sol(c)) % mod;  
    return 0;
}