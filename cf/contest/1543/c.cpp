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
double cc, mm, pp, v;

double sol(double c, double m, double p, double step) {
    double pre = 0.0;
    if(c) {
        if(c <= v && m) pre += sol(0, m+c/2, p+c/2, step+1.0)*c;
        else if(c <= v) pre += sol(0, 0, 1, step+1.0)*c;
        else if(!m) pre += sol(c-v, 0, p+v, step+1.0)*c;
        else pre += sol(c-v, m+v/2, p+v/2, step+1.0)*c;
    }
    if(m) {
        if(m <= v && c) pre += sol(c+m/2, 0, p+m/2, step+1.0)*m;
        else if(m <= v) pre += sol(0, 0, 1, step+1.0)*m;
        else if(!c) pre += sol(0, m-v, p+v, step+1.0)*m;
        else pre += sol(c+v/2, m-v, p+v/2, step+1.0)*m;
    }
    pre += step*p;
    return pre;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> cc >> mm >> pp >> v;
        printf("%.9f\n", sol(cc, mm, pp, 1.0));
    }
    return 0;
}