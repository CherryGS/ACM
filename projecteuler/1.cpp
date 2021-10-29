#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n = 1000;

void check() {
    ll ans = 0;
    for(int i=1; i<=999; i++) {
        if(!(i%3)) ans += i;
        else if(!(i%5)) ans += i;
    }
    cout << ans << "---" << endl;
}

int main() {
    check();
    ll ans = 0;
    ans += 3ll * (333+1) * 333 / 2;
    ans += 5ll * (199+1) * 199 / 2;
    ans -= 15ll * (999/15+1) * (999/15) / 2;
    cout << ans << endl;
    return 0;
}