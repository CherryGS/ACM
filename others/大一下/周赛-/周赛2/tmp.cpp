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

double ans=0.0;

int main() {
    double m;
    cin >> m;
    for(int i=1; i<=m; i++) ans += (1.0/i);
    printf("%.7f", ans);
    return 0;
}