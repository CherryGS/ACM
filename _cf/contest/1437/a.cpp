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

int t, l, r;

int main() {
    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(r-l < l) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}