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

ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int key = 24;
        if(((3*n)%key)) cout << "Impossible" << endl;
        else {
            ll b = (3*n)/24;
            cout << b*11 << ' ' << b*7 << ' ' << b*6 << endl;
        }
    }
    return 0;
}