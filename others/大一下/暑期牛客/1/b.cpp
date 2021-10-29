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

double r, a, b, h;

int main() {
    cin >> r >> a >> b >> h;
    if(2*r <= b) {
        cout << "Drop" << endl;
        return 0;
    }
    cout << "Stuck" << endl;
    double sn = 2.0*h/sqrt(pow(2.0*h, 2.0) + pow(a-b, 2.0));
    double l = r*sn;
    double ans = (2.0*l-b)/(double)(a-b)*(double)h + (double)r*sqrt(1-pow(sn, 2.0));
    printf("%.9f\n",ans) ;
    return 0;
}