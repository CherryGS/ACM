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

int n, m;


int main() {
    cin >> n >> m;
    double x;
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(x < m) printf("On Sale! %.1f\n", x);
    }
    return 0;
}