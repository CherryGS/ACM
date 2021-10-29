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

int n;
double c;
double a[100100];

int main() {
    cin >> n >> c;
    double pre = 0;
    for(int i=1; i<=n; i++) cin >> a[i], pre+=a[i];
    sort(a+1, a+1+n);
    double ans = c;
    double sum = 0.0;
    for(int i=1; i<n; i++) {
        sum += a[i];
        ans += sum / pow(2, n-i);
    }
    printf("%.9f\n", min(ans, pre));
    return 0;
}
/*
2 0.1
1000000000 1000000000
*/