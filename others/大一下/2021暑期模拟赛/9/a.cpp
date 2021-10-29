#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
double p, q;

int main() {
    cin >> t;
    while(t--) {
        cin >> p >> q;
        if(p <= q) cout << "N0 M0R3 BL4CK 1CE TEA!" << endl;
        else cout << "ENJ0Y YOURS3LF!" << endl;
    }
    return 0;
}