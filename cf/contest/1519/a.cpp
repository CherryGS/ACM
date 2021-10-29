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
ll r, b, d;

int main() {
    cin >> t;
    while(t--) {
        cin >> r >> b >> d;
        if(r < b) swap(r, b);
        if(b*(d+1) < r) cout << "NO" << endl;
        else cout << "yES" << endl;
    }
    return 0;
}