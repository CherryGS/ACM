#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

ull n, k;

ll p(ll x) {return x*x*x;}

int main() {
    cin >> n >> k;
    if(k%2) {
        cout << p(n/k);
    } else {
        cout << p(n/k) + p((n/(k>>1)+1)>>1);
    }
    return 0;
}