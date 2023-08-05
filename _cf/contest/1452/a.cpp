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

int t;

int main() {
    cin >> t;
    int x, y;
    while(t--) {
        cin >> x >> y;
        if(x<y) swap(x,y);
        if(x==y) cout << x+y << endl;
        else cout << x+y+(x-y-1) << endl;
    }
    return 0;
}