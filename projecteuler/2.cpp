#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll fib[4004000];

int main() {
    fib[0] = 1;
    fib[1] = 2;
    ll ans = 2;
    for(int i=2; ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > 4000000) break;
        if(!(fib[i]&1)) ans += fib[i];
    }
    cout << ans << endl;
    return 0;
}