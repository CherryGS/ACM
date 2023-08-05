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

ll h, m, a;
ll ans;

int main() {
    // cin >> h >> m >> a;
    h = 1000;
    m = 2000;
    a = 3000;
    for(int i=0; i<h; i++) {
        double p1 = (double)i/(h-1)*m;
        double p2 = p1 - a/(double)(h-1);
        double p3 = p1 + a/(double)(h-1);
    }
    return 0;
}