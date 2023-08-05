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
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, a, b, c, d;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        cout << max(a+b, c+d) << endl;
    }
    return 0;
}