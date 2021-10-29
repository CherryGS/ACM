#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll x = 600851475143;

int sol() {
    ll r = sqrt(x);
    ll ans = 0;
    for(int i=2; i<=r; i++) {
        while(!(x%i)) { x /= i; ans = i; }
    }
    return max(ans, x);
}

int main() {
    cout << sol() << endl;
    return 0;
}