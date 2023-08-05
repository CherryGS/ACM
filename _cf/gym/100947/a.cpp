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
int x, g, y, r;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> x >> y >> g >> r;
        x %= (y+g+r);
        if(x < y) cout << "GREEN" << endl;
        else if(x < y+g) cout << "YELLOW" << endl;
        else cout << "RED" << endl;
    }
    return 0;
}