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
double k, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> k >> x >> y;
        if(!x || y/x >= k) cout << "0.000" << endl;
        else printf("%.3f\n", (x*k-y)*y/k*2.0);
    }
    return 0;
}