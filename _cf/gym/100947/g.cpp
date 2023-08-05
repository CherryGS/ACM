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
ll x, y;

ll sol(ll x) {
    return (2*x)*(2*x-1);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> x >> y;
        if(abs(y) >= abs(x)) {
            cout << sol(y) + abs(x-y) << endl;
        } else {
            cout << sol(x) - abs(x-y) << endl;
        }
    }
    return 0;
}