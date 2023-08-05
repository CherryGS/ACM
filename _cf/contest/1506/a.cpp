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
ll n, m, x;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m >> x;
        ll a1 = x % n;
        ll a2 = (x+n-1) / n ;
        if(a1 == 0) a1 = n;
        cout << (a1-1)*m + a2 << endl;
    }
    return 0;
}