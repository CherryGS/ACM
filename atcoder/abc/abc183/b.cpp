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

double x[2],y[2];

int main() {
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    if(x[0] < x[1]) printf("%.9f", x[0] + (y[0]/(y[0]+y[1])*(x[1]-x[0])));
    else printf("%.9f", x[1] + (y[1]/(y[0]+y[1])*(x[0]-x[1])));
    return 0;
}