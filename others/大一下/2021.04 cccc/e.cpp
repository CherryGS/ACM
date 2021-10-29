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

int a[25];

int main() {
    for(int i=1; i<=24; i++) cin >> a[i];
    while(1) {
        int x;
        cin >> x;
        if(0 > x || x > 23) break;
        if(a[x+1] > 50) cout << a[x+1] << " Yes" << endl;
        else cout << a[x+1] << " No" << endl;
    }
    return 0;
}