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
int c, d, x;

int main() {
    cin >> t;
    while(t--) {
        cin >> c >> d >> x;
        cout << (d+x)/c << ' ' << d/c << endl;
    }
    return 0;
}
/*
1
1 6006000 8008000
*/