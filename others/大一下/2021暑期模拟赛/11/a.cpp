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
ll p, a, b, c;

int main() {
    cin >> t;
    while(t--) {
        cin >> p >> a >> b >> c;
        ll s1 = p%a;
        ll s2 = p%b;
        ll s3 = p%c;
        if(!s1) s1 = a;
        if(!s2) s2 = b;
        if(!s3) s3 = c;
        cout << min(min(a-s1, b-s2), c-s3) << endl;
    }
    return 0;
}