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

int m, l, r;

double deal(double x, double y) {
    return sqrt(2.0*sqrt(pow(x-1,2.0)+pow(y-1,2.0)));
}

int main() {
    cin >> m >> l >> r;
    printf("%.9f", (deal(l, m)+deal(r, m))/2.0);
    return 0;
}